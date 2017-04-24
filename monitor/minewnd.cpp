#include "minewnd.h"
#include "serialport.h"

MineWnd::MineWnd(unsigned char id, QString title, QWidget *parent) : QWidget(parent)
, m_id(id)
, m_pTitle(0)
, m_pVoltageValueName(0)
, m_pVoltageValueUnit(0)
, m_pCurrentValueName(0)
, m_pCurrentValueUnit(0)
, m_pInstantFluxName(0)
, m_pInstantFluxUnit(0)
, m_pCountFluxName(0)
, m_pCountFluxUnit(0)
, m_pLevelValueName(0)
, m_pLevelValueUnit(0)
, m_pVoltageValue(0)
, m_pCurrentValue(0)
, m_pInstantFlux(0)
, m_pCountFlux(0)
, m_pLevelValue(0)
, m_pPumpRunName(0)
, m_pPumpHitchName(0)
, m_pPumpAlarmName(0)
, m_pPumpRunImage(0)
, m_pPumpHitchImage(0)
, m_pPumpAlarmImage(0)
, m_pTelecontrol(0)
, m_pStartStop(0)
, m_pGroupBox(0)
, m_pGLayout(0)
, m_pGLayoutLed(0)
, m_pHLayoutButton(0)
, m_pVLayout(0)
, m_pVLayoutMain(0)
, m_startStop(Start)
, m_teleControl(TeleAllow)
{
	m_pTitle = new QCheckBox(title);

	m_pVoltageValueName = new QLabel(tr("Voltage Value"));
	m_pVoltageValueUnit = new QLabel(tr("V"));
	m_pCurrentValueName = new QLabel(tr("Current Value"));
	m_pCurrentValueUnit = new QLabel(tr("A"));
	m_pInstantFluxName = new QLabel(tr("Instant Flux"));
	m_pInstantFluxUnit = new QLabel(tr("T/h"));
	m_pCountFluxName = new QLabel(tr("Count Flux"));
	m_pCountFluxUnit = new QLabel(tr("T"));
	m_pLevelValueName = new QLabel(tr("Level Value"));
	m_pLevelValueUnit = new QLabel(tr("m"));

	m_pVoltageValue = new QLineEdit;
	m_pCurrentValue = new QLineEdit;
	m_pInstantFlux = new QLineEdit;
	m_pCountFlux = new QLineEdit;
	m_pLevelValue = new QLineEdit;


	m_pPumpRunName = new QLabel(tr("Pump Run"));
	m_pPumpHitchName = new QLabel(tr("Pump Hitch"));
	m_pPumpAlarmName = new QLabel(tr("Pump Alarm"));

	m_pPumpRunImage = new QLabel;
	m_pPumpHitchImage = new QLabel;
	m_pPumpAlarmImage = new QLabel;

	m_pPumpRunImage->setPixmap(QPixmap("./image/green.png"));
	m_pPumpHitchImage->setPixmap(QPixmap("./image/green.png"));
	m_pPumpAlarmImage->setPixmap(QPixmap("./image/green.png"));

	m_pTelecontrol = new QPushButton(tr("Tele Allow"));	
	m_pStartStop = new QPushButton(tr("Pump Start"));

	m_pGroupBox = new QGroupBox;

	m_pGLayout = new QGridLayout;
	m_pHLayoutTitle = new QHBoxLayout;
	m_pGLayoutLed = new QGridLayout;
	m_pHLayoutButton = new QHBoxLayout;
	m_pVLayout = new QVBoxLayout;
	m_pVLayoutMain = new QVBoxLayout;

	m_pVLayoutMain->setContentsMargins(10, 0, 10, 0);

	m_pVLayout->setAlignment(Qt::AlignCenter);
	m_pVLayoutMain->setAlignment(Qt::AlignHCenter);

	m_pGLayout->addWidget(m_pVoltageValueName, 0, 0, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pVoltageValue, 0, 1, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pVoltageValueUnit, 0, 2, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pCurrentValueName, 0, 3, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pCurrentValue, 0, 4, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pCurrentValueUnit, 0, 5, Qt::AlignCenter);

	m_pGLayout->addWidget(m_pInstantFluxName, 1, 0, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pInstantFlux, 1, 1, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pInstantFluxUnit, 1, 2, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pCountFluxName, 1, 3, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pCountFlux, 1, 4, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pCountFluxUnit, 1, 5, Qt::AlignCenter);

	m_pGLayout->addWidget(m_pLevelValueName, 2, 0, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pLevelValue, 2, 1, Qt::AlignCenter);
	m_pGLayout->addWidget(m_pLevelValueUnit, 2, 2, Qt::AlignCenter);

	m_pGLayoutLed->addWidget(m_pPumpRunName, 0, 0, Qt::AlignCenter);
	m_pGLayoutLed->addWidget(m_pPumpHitchName, 0, 1, Qt::AlignCenter);
	m_pGLayoutLed->addWidget(m_pPumpAlarmName, 0, 2, Qt::AlignCenter);
	m_pGLayoutLed->addWidget(m_pPumpRunImage, 1, 0, Qt::AlignCenter);
	m_pGLayoutLed->addWidget(m_pPumpHitchImage, 1, 1, Qt::AlignCenter);
	m_pGLayoutLed->addWidget(m_pPumpAlarmImage, 1, 2, Qt::AlignCenter);

	m_pHLayoutButton->addWidget(m_pTelecontrol);
	m_pHLayoutButton->addWidget(m_pStartStop);

	m_pVLayout->addLayout(m_pGLayout);
	m_pVLayout->addLayout(m_pGLayoutLed);
	m_pVLayout->addLayout(m_pHLayoutButton);

	m_pGroupBox->setLayout(m_pVLayout);

	m_pVLayoutMain->addWidget(m_pTitle);
	m_pVLayoutMain->addWidget(m_pGroupBox);

	this->setLayout(m_pVLayoutMain);

	connect(m_pStartStop, SIGNAL(clicked()), this, SLOT(slot_startStop()));
	connect(m_pTelecontrol, SIGNAL(clicked()), this, SLOT(slot_telecontrol()));
	connect(m_pTitle, SIGNAL(stateChanged(int)), this, SIGNAL(checkBoxCahanged(int)));
}

MineWnd::~MineWnd()
{
	delete m_pTitle;
	delete m_pVoltageValueName;
	delete m_pVoltageValueUnit;
	delete m_pCurrentValueName;
	delete m_pCurrentValueUnit;
	delete m_pInstantFluxName;
	delete m_pInstantFluxUnit;
	delete m_pCountFluxName;
	delete m_pCountFluxUnit;
	delete m_pLevelValueName;
	delete m_pLevelValueUnit;
	delete m_pPumpRunName;
	delete m_pPumpHitchName;
	delete m_pPumpAlarmName;
	delete m_pPumpRunImage;
	delete m_pPumpHitchImage;
	delete m_pPumpAlarmImage;
	delete m_pVoltageValue;
	delete m_pCurrentValue;
	delete m_pInstantFlux;
	delete m_pCountFlux;
	delete m_pLevelValue;
	delete m_pTelecontrol;
	delete m_pStartStop;
	delete m_pGLayout;
	delete m_pGLayoutLed;
	delete m_pHLayoutButton;
	delete m_pVLayout;
	delete m_pVLayoutMain;
}

QSize MineWnd::sizeHint() const
{
	return QSize(400, 250);
}

void MineWnd::setVoltageValue(double value)
{
	m_pVoltageValue->setText(QString::number(value, 'f', 1));
}

void MineWnd::setCurrentValue(double value)
{
	m_pCurrentValue->setText(QString::number(value, 'f', 1));
}

void MineWnd::setInstantFlux(double value)
{
	m_pInstantFlux->setText(QString::number(value, 'f', 1));
}

void MineWnd::setCountFlux(double value)
{
	m_pCountFlux->setText(QString::number(value, 'f', 1));
}

void MineWnd::setLevelValue(double value)
{
	m_pLevelValue->setText(QString::number(value, 'f', 1));
}

void MineWnd::setLed(Led led, bool bl)
{
	switch (led)
	{
	case Run:
		if (bl)
		{
			m_pPumpRunImage->setPixmap(QPixmap("./image/red.png"));
		}
		else
		{
			m_pPumpRunImage->setPixmap(QPixmap("./image/green.png"));
		}
		break;
	case Hitch:
		if (bl)
		{
			m_pPumpHitchImage->setPixmap(QPixmap("./image/red.png"));
		}
		else
		{
			m_pPumpHitchImage->setPixmap(QPixmap("./image/green.png"));
		}
		break;
	case Alarm:
		if (bl)
		{
			m_pPumpAlarmImage->setPixmap(QPixmap("./image/red.png"));
		}
		else
		{
			m_pPumpAlarmImage->setPixmap(QPixmap("./image/green.png"));
		}
		break;
	default:
		break;
	}
}

void MineWnd::slot_telecontrol()
{
	if (!SerialPort::getInstance()->m_bIsSend)
	{
		switch (m_teleControl)
		{
		case TeleAllow:
			if (!SerialPort::getInstance()->m_bIsSend)
			{
				SerialPort::getInstance()->setWriteAddressState(m_id, 10, SerialPort::Close);
				SerialPort::getInstance()->m_bIsSend = true;
				m_pTelecontrol->setText(tr("Tele Ban"));
				m_teleControl = TeleBan;
			}
			break;
		case TeleBan:
			if (!SerialPort::getInstance()->m_bIsSend)
			{
				SerialPort::getInstance()->setWriteAddressState(m_id, 10, SerialPort::Open);
				SerialPort::getInstance()->m_bIsSend = true;
				m_pTelecontrol->setText(tr("Tele Allow"));
				m_teleControl = TeleAllow;
			}
			break;
		default:
			break;
		}
	}
}

void MineWnd::slot_startStop()
{
	if (!SerialPort::getInstance()->m_bIsSend)
	{
		switch (m_startStop)
		{
		case Start:
			if (!SerialPort::getInstance()->m_bIsSend)
			{
				SerialPort::getInstance()->setWriteAddressState(m_id, 11, SerialPort::Close);
				SerialPort::getInstance()->m_bIsSend = true;
				m_pStartStop->setText(tr("Pump Stop"));
				m_startStop = Stop;
			}
			break;
		case Stop:
			if (!SerialPort::getInstance()->m_bIsSend)
			{
				SerialPort::getInstance()->setWriteAddressState(m_id, 11, SerialPort::Open);
				SerialPort::getInstance()->m_bIsSend = true;
				m_pStartStop->setText(tr("Pump Start"));
				m_startStop = Start;
			}
			break;
		default:
			break;
		}
	}
}

