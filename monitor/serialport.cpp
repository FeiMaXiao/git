#include "serialport.h"
#include "datamanager.h"
#include <winsock.h>

SerialPort * SerialPort::m_pInstance = 0;

SerialPort::SerialPort(QObject *parent) : QObject(parent)
, m_pModbus(0)
, m_bIsOpen(false)
, m_bIsSend(false)
, m_readId(1)
, m_writeAddress(10)
, m_writeState(SerialPort::Close)
{

}

SerialPort::~SerialPort()
{

}

SerialPort* SerialPort::getInstance()
{
	if (0 == m_pInstance)
	{
		m_pInstance = new SerialPort();
	}
	return m_pInstance;
}

bool SerialPort::open(CommSet::Settings setting)
{
	QByteArray byte;
	byte = setting.name.toLatin1();
	m_pModbus = modbus_new_rtu(byte.data(), setting.baudRate, setting.parity, setting.dataBits, setting.stopBits);
	modbus_rtu_set_serial_mode(m_pModbus, MODBUS_RTU_RS485);
	if (m_pModbus)
	{
		struct timeval t;
		t.tv_sec = 0;
		t.tv_usec = 1000 * setting.commTimeout;
		modbus_set_response_timeout(m_pModbus, &t);
		modbus_set_slave(m_pModbus, 1);
		modbus_connect(m_pModbus);
		m_bIsOpen = true;
		m_timeSpace = setting.commSpace;
		return true;
	}
	return false;
}

bool SerialPort::isOpen()
{
	return m_bIsOpen;
}

void SerialPort::close()
{
	if (m_pModbus)
	{
		modbus_close(m_pModbus);
		modbus_free(m_pModbus);
	}
}

bool SerialPort::readDIState(int address, int num)
{
	uint8_t tab_reg[32] = { 0 };

	if (modbus_read_input_bits(m_pModbus, address, num, tab_reg) == num)
	{
		if (m_readId > 0)
		{
			DataManager::getInstance()->m_vecWellData[m_readId - 1]->di1 = tab_reg[0];
			DataManager::getInstance()->m_vecWellData[m_readId - 1]->di2 = tab_reg[1];
			DataManager::getInstance()->m_vecWellData[m_readId - 1]->di3 = tab_reg[2];
			DataManager::getInstance()->m_vecWellData[m_readId - 1]->di4 = tab_reg[3];
			return true;
		}

		return false;
	}
	return false;
}

bool SerialPort::readElectricalValue(int address, int num)
{
	uint16_t tab_reg[32] = { 0 };

	if (modbus_read_registers(m_pModbus, address, num, tab_reg) == num)
	{
		if (m_readId > 0)
		{
			DataManager::getInstance()->m_vecWellData[m_readId - 1]->ullAvg = tab_reg[0];
			DataManager::getInstance()->m_vecWellData[m_readId - 1]->iAvg = tab_reg[8];
			return true;
		}

		return false;
	}
	return false;
}

bool SerialPort::setDOState()
{
	if (modbus_write_bit(m_pModbus, m_writeAddress, m_writeState))
	{
		return true;
	}
	return false;
}

bool SerialPort::setReadId(int id)
{
	if (modbus_set_slave(m_pModbus, id) == 0)
	{
		m_readId = id;
		return true;
	}

	return false;
}

bool SerialPort::setWriteAddressState(int id, int address, CoilState state)
{
	if (modbus_set_slave(m_pModbus, id) == 0)
	{
		m_writeAddress = address;
		m_writeState = state;
		return true;
	}

	return false;
}

