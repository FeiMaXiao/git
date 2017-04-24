#include "connectdb.h"
#include <QDebug>
#include "datamanager.h"

ConnectDB::ConnectDB(QObject *parent)
: QObject(parent)
{

}

ConnectDB::ConnectDB(QString addr, QString username, QString password, QString databasename, int port, QObject *parent) : QObject(parent)
{
	//interval = 1000*60;

	db = QSqlDatabase::addDatabase("QPSQL");
	db.setHostName(addr);
	db.setDatabaseName(databasename);
	db.setPort(port);
	db.setUserName(username);
	db.setPassword(password);
	isopen = isOpen();
	m_pTimer = new QTimer(this);
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
	/*QStringList s;
	s << "1" << "10.0" << "11.1";
	for (int i = 0; i < 40; ++i){
		s[0] = QString::number(i + 1);
		DBaddWellPos(s);
	}*/

	//setInterval(interval);

}
ConnectDB::~ConnectDB()
{

}

bool ConnectDB::isOpen()
{
	if (db.open())
	{
		return true;
	}
	else{
		return false;
	}
}

bool ConnectDB::DBadd(QStringList slist)
{
	if (slist.size() < 8)
	{
		return false;
	}
	QSqlQuery SqlQuery;
	QString strsql = "INSERT INTO welldb VALUES    (";
	strsql += slist.at(0) + ", '" + slist.at(1) + "' ," + slist.at(2) + "," + slist.at(3) + "," + slist.at(4) + "," + \
		slist.at(5) + ", " + slist.at(6) + ",'" + slist.at(7) + "')";
	isok = SqlQuery.exec(strsql);

	if (!isok)
	{
		//query.
	}
	//query.clear();
	return isok;
}

bool ConnectDB::DBdel(QStringList slist)
{
	if (slist.size() < 2)
	{
		return false;
	}
	QSqlQuery SqlQuery;
	QString strsql = "DELETE FROM welldb    ";
	strsql += "where wid = " + slist.at(0) + " and time = '" + slist.at(1) + "'";
	isok = SqlQuery.exec(strsql);

	if (!isok)
	{
		//query.
	}
	//query.clear();
	return isok;
}

bool ConnectDB::DBset(QStringList slist)
{
	if (slist.size() < 8)
	{
		return false;
	}
	QSqlQuery SqlQuery;

	QString strsql = "UPDATE welldb SET";
	strsql += " wid = " + slist.at(0) + ", time = '" + slist.at(1) + "', ullAvg = " + slist.at(2) + ", iAvg = " + slist.at(3) + \
		", instantFlux = " + slist.at(4) + ", countFlux = " + slist.at(5) + ", levelValue = " + slist.at(6) + \
		", warninginfo = '" + slist.at(7) + "'";
	strsql += " where wid = " + slist.at(0) + " and time = '" + slist.at(1) + "'";

	isok = SqlQuery.exec(strsql);


	if (!isok)
	{
		//query.
	}
	//query.clear();
	return isok;
}

QStringList ConnectDB::DBget(QStringList slist)
{
	QStringList resultList;
	if (slist.size() < 2)
	{
		return resultList;
	}
	QSqlQuery SqlQuery;
	QString strsql = "SELECT * FROM welldb ";
	strsql += "where wid = " + slist.at(0) + " and time = '" + slist.at(1) + "'";
	isok = SqlQuery.exec(strsql);

	QString s = "";
	SqlQuery.next();
	for (int i = 0; i < 8; ++i)
	{
		s = SqlQuery.value(i).toString();
		resultList.append(s);
	}

	if (!isok)
	{
		//query.
	}
	//query.clear();
	return resultList;
}

void ConnectDB::setInterval(int _interval)
{
	interval = _interval;
	m_pTimer->start(interval);
}

void ConnectDB::slot_timeout()
{
	InsertDataToDB();
}

void ConnectDB::InsertDataToDB()
{
	QStringList sList;
	QString time = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
	QVector<DataManager::MeterData *> VectorMeterData = DataManager::getInstance()->m_vecWellData;

	for (int i = 0; i < VectorMeterData.size(); ++i)
	{
		DataManager::MeterData *meterData = VectorMeterData.at(i);
		sList.clear();
		sList.append(QString::number(i + 1));
		sList.append(time);
		sList.append(QString::number(meterData->ullAvg));
		sList.append(QString::number(meterData->iAvg));
		sList.append(QString::number(meterData->instantFlux));
		sList.append(QString::number(meterData->countFlux));
		sList.append(QString::number(meterData->levelValue));
		sList.append("OK");
		DBadd(sList);
	}
}

void ConnectDB::slot_startDB()
{
	setInterval(60 * 1000);
}

bool ConnectDB::DBaddWellPos(QStringList slist)
{
	if (slist.size() < 3)
	{
		return false;
	}
	QSqlQuery SqlQuery;
	QString strsql = "INSERT INTO wellposdb VALUES    (";
	strsql += slist.at(0) + ", " + slist.at(1) + " ," + slist.at(2) + ")";
	isok = SqlQuery.exec(strsql);

	if (!isok)
	{
		//query.
	}
	//query.clear();
	return isok;
}

