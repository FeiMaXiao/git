#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QVector>

class DataManager
{
public:
	typedef struct MeterDataStruct
	{
		short ullAvg;
		short iAvg;
		short instantFlux;
		short countFlux;
		short levelValue;
		unsigned char di1;
		unsigned char di2;
		unsigned char di3;
		unsigned char di4;

		MeterDataStruct()
		{
			ullAvg = 0;
			iAvg = 0;
			instantFlux = 0;
			countFlux = 0;
			levelValue = 0;
			di1 = 0;
			di2 = 0;
			di3 = 0;
			di4 = 0;
		}
	}MeterData;

	explicit DataManager();
	~DataManager();
	void dataDelete();
	void setMeterDataNum(int num);
	static DataManager * getInstance();

public:
	QVector<MeterData *> m_vecWellData;

private:
	static DataManager *m_pInstance;
};

#endif // DATAMANAGER_H
