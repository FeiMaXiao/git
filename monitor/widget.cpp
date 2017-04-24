#include "widget.h"
#include "datamanager.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
, m_pLeft(0)
, m_pRight(0)
{
	m_pLeft = new QTabWidget;
	m_pRight = new ScrollTabCtl;
	m_pLeft->setTabPosition(QTabWidget::South);

	QStringList hLabel;
	hLabel.append(tr("Voltage Value") + tr("(T)"));
	hLabel.append(tr("Current Value") + tr("(A)"));
	hLabel.append(tr("Instant Flux") + tr("(T/h)"));
	hLabel.append(tr("Count Flux") + tr("(T)"));
	hLabel.append(tr("Level Value") + tr("(m)"));

	DataManager::getInstance()->setMeterDataNum(40);

	m_pDataTable = new RtDataTableWnd(40, 5, hLabel);
	//m_pRtWave = new RtWaveWnd;

	m_pPlotLineWnd = new PlotLines;

#define  DEBUG
#ifdef DEBUG
	QVector<QPointF> vecPoint;
	for (int i = 0; i < 600; ++i)
	{
		float x = i / 10;
		float y = i / 6;
		vecPoint.push_back(QPointF(x, y));
	}
	m_pPlotLineWnd->setData(vecPoint);
#endif


	m_pGis = new GisWnd;
	m_pWell = new WellWnd(40);

	m_pHLayout = new QHBoxLayout;

	m_pLeft->addTab(m_pDataTable, tr("Rt Data"));
	m_pLeft->addTab(m_pPlotLineWnd, tr("Rt Wave"));
	m_pLeft->addTab(m_pGis, tr("Map"));

	m_pRight->addPage(m_pWell, tr("Well"));

	m_pHLayout->addWidget(m_pLeft, 7);
	m_pHLayout->addWidget(m_pRight, 2);

	this->setLayout(m_pHLayout);
}

Widget::~Widget()
{
	delete m_pLeft;
	delete m_pRight;
}

void Widget::slot_setMapSatellite()
{
	if (m_pGis->getMapType() != MapType::GoogleSatelliteChina)
	{
		m_pGis->setMapType(MapType::GoogleSatelliteChina);
	}
}

void Widget::slot_setMapHybrid()
{
	if (m_pGis->getMapType() != MapType::GoogleHybridChina)
	{
		m_pGis->setMapType(MapType::GoogleHybridChina);
	}
}

void Widget::slot_MapCreateWp(double lat, double lng)
{
	m_pGis->createWp(lat, lng);
}

void Widget::slot_MapClearWp()
{
	m_pGis->clearWp();
}

void Widget::slot_wellData(int id)
{
	m_pWell->showData(id);
}

void Widget::slot_wellState(int id)
{
	m_pWell->setLed(id);
}



