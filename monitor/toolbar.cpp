#include "toolbar.h"

ToolBar::ToolBar(QWidget * parent) : QToolBar(parent)
{
	m_pToolBtn = new QToolButton;
	m_pToolBtn->setText(tr("Test Map"));
	
	m_pTestMap = new TestMap(parent);
	m_pTestMap->hide();

	this->addWidget(m_pToolBtn);

	connect(m_pToolBtn, SIGNAL(clicked()), this, SLOT(slot_testMap()));
	connect(m_pTestMap, SIGNAL(signal_latLng(double, double)), this, SIGNAL(signal_testMapLatLng(double, double)));
	connect(m_pTestMap, SIGNAL(signal_clearWp()), this, SIGNAL(signal_testMapClear()));
}

ToolBar::~ToolBar()
{
	delete m_pToolBtn;
}

void ToolBar::slot_testMap()
{
	m_pTestMap->show();
}

