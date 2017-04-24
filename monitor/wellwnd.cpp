#include "wellwnd.h"
#include "datamanager.h"

WellWnd::WellWnd(int mineCount, QWidget *parent) : QWidget(parent)
, m_pVLayout(0)
, m_id(0)
{
	m_pVLayout = new QVBoxLayout;

	for (int i = 0; i<mineCount; ++i)
	{
		MineWnd *pMineWnd = new MineWnd(i + 1, QString::number(i + 1) + "#" + tr("Well"));
		m_vecMine.append(pMineWnd);
		m_pVLayout->addWidget(pMineWnd);
	}

	m_pVLayout->addStretch();

	m_pVLayout->setContentsMargins(0, 0, 0, 0);

	this->setLayout(m_pVLayout);
}

WellWnd::~WellWnd()
{
	delete m_pVLayout;
	for (int i = 0; i<m_vecMine.size(); ++i)
	{
		delete m_vecMine.at(i);
	}
}

void WellWnd::setLed(int id)
{
	if ((id >= 0) && (id < 40))
	{
		m_vecMine.at(id)->setLed(MineWnd::Run, DataManager::getInstance()->m_vecWellData[id]->di1);
		m_vecMine.at(id)->setLed(MineWnd::Hitch, DataManager::getInstance()->m_vecWellData[id]->di2);
		m_vecMine.at(id)->setLed(MineWnd::Alarm, DataManager::getInstance()->m_vecWellData[id]->di3);
	}
}

void WellWnd::showData(int id)
{
	if ((id >= 0) && (id < 40))
	{
		double voltage = DataManager::getInstance()->m_vecWellData[id]->ullAvg / 100;
		m_vecMine.at(id)->setVoltageValue(voltage);

		double current = DataManager::getInstance()->m_vecWellData[id]->iAvg / 1000;
		m_vecMine.at(id)->setCurrentValue(current);

		double instantFlux = DataManager::getInstance()->m_vecWellData[id]->instantFlux;
		m_vecMine.at(id)->setInstantFlux(instantFlux);

		double countFlux = DataManager::getInstance()->m_vecWellData[id]->countFlux;
		m_vecMine.at(id)->setCountFlux(countFlux);

		double levelValue = DataManager::getInstance()->m_vecWellData[id]->levelValue / 1000;
		m_vecMine.at(id)->setLevelValue(levelValue);
	}
}
