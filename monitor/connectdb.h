#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QObject>
#include <QtSql>
#include <QTimer>


/*wid, iid, level, rateflow, voltage, current, warninginfo, datetime*/

class ConnectDB : public QObject
{
	Q_OBJECT

public:
	ConnectDB(QObject *parent = NULL);
	ConnectDB(QString addr, QString username, QString password, QString databasename, int port, QObject *parent = 0);
	~ConnectDB();

	void setInterval(int _interval);
	bool isOpen();
	bool DBadd(QStringList slist);
	bool DBdel(QStringList slist);
	bool DBset(QStringList slist);
	QStringList DBget(QStringList slist);
	bool DBaddWellPos(QStringList slist);        //添加井的经纬坐标

	QSqlDatabase db;
	bool isopen;
	bool isok;
	int interval;
	QTimer *m_pTimer;
	QSqlQuery query;
private:
signals :
	void timeout();
		public slots :
		void slot_timeout();
		void InsertDataToDB();
		void slot_startDB();

		//public:
		//    static ConnectDB * getInstance(){
		//        if (0 == m_pInstance)
		//        {
		//            m_pInstance = new ConnectDB();
		//        }
		//        return m_pInstance;
		//    };
		//private:
		//    static ConnectDB *m_pInstance;
};

#endif // CONNECTDB_H

