#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
	, m_pCommType(0)
	, m_pCommState(0)
{
	m_pCommType = new QLabel(tr("Comm Type: ") + tr("Serial"));
	m_pCommState = new QLabel(tr("Comm State: ") + tr("Disconnect"));

	m_pCommType->setStyleSheet("QLabel{background:transparent;color:red}");
	m_pCommState->setStyleSheet("QLabel{background:transparent;color:red}");

	this->addWidget(m_pCommType);
	this->addWidget(m_pCommState);
}

StatusBar::~StatusBar()
{
	delete m_pCommType;
	delete m_pCommState;
}

void StatusBar::slot_CommState(CommSet::CommState state)
{
	switch (state)
	{
	case CommSet::Connect:
		m_pCommState->setText(tr("Comm State: ") + tr("Connect"));
		break;
	case CommSet::Disconnect:
		m_pCommState->setText(tr("Comm State: ") + tr("Disconnect"));
		break;
	case CommSet::Error:
		m_pCommState->setText(tr("Comm State: ") + tr("Error"));
	}
}

void StatusBar::slot_CommType(CommSet::CommType type)
{
	switch (type)
	{
	case CommSet::Serial:
		m_pCommState->setText(tr("Comm Type: ") + tr("Serial"));
		break;
	case CommSet::Net:
		m_pCommState->setText(tr("Comm Type: ") + tr("Net"));
		break;
	default:
		break;
	}
}

