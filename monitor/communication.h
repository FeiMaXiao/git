#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QThread>
#include "serialport.h"

class Communication : public QThread
{
	Q_OBJECT
public:
	explicit Communication(QObject *parent = 0);
	~Communication();
	void startThread();
	void stopThread();
	unsigned short crc_16(unsigned char *array, unsigned int len);

protected:
	void run();

signals:
	void signal_commType(CommSet::CommType type);
	void signal_commState(CommSet::CommState state);
	void signal_readValueId(int id);
	void signal_readStateId(int id);

	public slots :
	void slot_setComm();

private:
	QWidget *m_pParent;
	bool m_threadFlag;
	int m_id;
	int m_cmdCount;
};

#endif // COMMUNICATION_H
