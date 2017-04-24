#include "datamanager.h"

DataManager * DataManager::m_pInstance = 0;

DataManager::DataManager()
{

}

DataManager::~DataManager()
{

}

void DataManager::dataDelete()
{
	for (int i = 0; i < m_vecWellData.size(); i++)
	{
		delete m_vecWellData.at(i);
	}

	m_vecWellData.clear();
}

void DataManager::setMeterDataNum(int num)
{
	if (num <= 0)
	{
		return;
	}

	for (int i = 0; i < num; i++)
	{
		m_vecWellData.append(new MeterData);
	}
}

DataManager* DataManager::getInstance()
{
	if (0 == m_pInstance)
	{
		m_pInstance = new DataManager();
	}
	return m_pInstance;
}

