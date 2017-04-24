#include "communication.h"
#include "datamanager.h"

Communication::Communication(QObject *parent) : QThread(parent)
, m_pParent(static_cast<QWidget *>(parent))
, m_threadFlag(false)
, m_id(1)
, m_cmdCount(0)
{

}

Communication::~Communication()
{
	m_threadFlag = false;
	this->wait();
	SerialPort::getInstance()->close();
	DataManager::getInstance()->dataDelete();
}

void Communication::startThread()
{
	m_threadFlag = true;
	this->start();
}

void Communication::stopThread()
{
	m_threadFlag = false;
	this->wait();
}

void Communication::run()
{
	while (m_threadFlag)
	{
		if (SerialPort::getInstance()->m_bIsSend)
		{
			SerialPort::getInstance()->setDOState();
			SerialPort::getInstance()->m_bIsSend = false;
			SerialPort::getInstance()->setReadId(m_id);
		}
		else
		{
			m_cmdCount++;
			switch (m_cmdCount)
			{
			case 1:
				if (SerialPort::getInstance()->readDIState(100, 4))
				{
					emit signal_readStateId(m_id - 1);
				}
				break;
			case 2:
				m_cmdCount = 0;
				if (SerialPort::getInstance()->readElectricalValue(123, 9))
				{
					emit signal_readValueId(m_id - 1);
				}
				m_id++;
				if (m_id > 40)
				{
					m_id = 1;
				}
				SerialPort::getInstance()->setReadId(m_id);
				break;
			default:
				m_cmdCount = 0;
				break;
			}
		}
		QThread::msleep(SerialPort::getInstance()->m_timeSpace);
	}
}

void Communication::slot_setComm()
{
	CommSet comm(m_pParent);
	comm.move(200, 200);
	if (comm.exec() == QDialog::Accepted)
	{
		if (SerialPort::getInstance()->isOpen())
		{
			this->stopThread();
			SerialPort::getInstance()->close();
		}

		if (SerialPort::getInstance()->open(comm.currentSettings))
		{
			emit signal_commState(CommSet::Connect);
			this->startThread();
			connect(SerialPort::getInstance(), SIGNAL(signal_recData(QByteArray)), this, SIGNAL(signal_sRec(QByteArray)));
		}
		else
		{
			emit signal_commState(CommSet::Error);
		}
	}
}
