#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "modbus/modbus.h"
#include "commset.h"

class SerialPort : public QObject
{
	Q_OBJECT
public:
	typedef enum{
		Open = 0,
		Close
	}CoilState;

	explicit SerialPort(QObject *parent = 0);
	~SerialPort();

	bool open(CommSet::Settings setting);
	bool isOpen();
	void close();
	bool readDIState(int address, int num);
	bool readElectricalValue(int address, int num);
	bool setDOState();
	bool setReadId(int id);
	bool setWriteAddressState(int id, int address, CoilState state = Close);

	static SerialPort * getInstance();

signals:
	void signal_recData(QByteArray b);

	public slots:

public:
	bool m_bIsSend;
	unsigned m_timeSpace;

private:
	modbus_t *m_pModbus;
	int m_readId;
	int m_writeAddress;
	CoilState m_writeState;
	static SerialPort *m_pInstance;
	bool m_bIsOpen;
};

#endif // SERIALPORT_H
