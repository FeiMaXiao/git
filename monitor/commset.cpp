#include "commset.h"
#include <QtSerialPort/QSerialPortInfo>

CommSet::CommSet(QWidget *parent) : QDialog(parent)
, m_pSerialPortInfoLabel(0)
, m_pBaudLabel(0)
, m_pDataBitLabel(0)
, m_pParityLabel(0)
, m_pStopBitLabel(0)
, m_pTimeOutUnit(0)
, m_pSpaceUnit(0)
, m_pTimeOutSpinBox(0)
, m_pSpaceSpinBox(0)
, m_pSerialPortInfo(0)
, m_pBaud(0)
, m_pDataBit(0)
, m_pParity(0)
, m_pStopBit(0)
, m_pStart(0)
, m_pCommType(0)
, m_pServerIPLabel(0)
, m_pServerIP(0)
, m_pPortLabel(0)
, m_pPort(0)
, m_pGroupBoxSerial(0)
, m_pGroupBoxNet(0)
, m_pGroupBoxTimeout(0)
, m_pStackedWidget(0)
, m_pGLayoutSerial(0)
, m_pGLayoutNet(0)
, m_pVLayout(0)
{
	this->setWindowTitle(tr("COMM Set"));

	m_pCommTypeLabel = new QLabel(tr("Comm Type"));
	m_pSerialPortInfoLabel = new QLabel(tr("Port Num"));
	m_pBaudLabel = new QLabel(tr("Baud"));
	m_pDataBitLabel = new QLabel(tr("Data Bit"));
	m_pParityLabel = new QLabel(tr("Parity"));
	m_pStopBitLabel = new QLabel(tr("Stop Bit"));

	m_pTimeOutLabel = new QLabel(tr("Comm Timeout"));
	m_pSpaceLabel = new QLabel(tr("Comm Space"));


	m_pTimeOutUnit = new QLabel(tr("ms"));
	m_pSpaceUnit = new QLabel(tr("ms"));

	m_pTimeOutSpinBox = new QSpinBox;
	m_pSpaceSpinBox = new QSpinBox;

	m_pTimeOutSpinBox->setRange(100, 1000);
	m_pSpaceSpinBox->setRange(100, 1000);

	m_pTimeOutSpinBox->setValue(100);
	m_pSpaceSpinBox->setValue(200);

	m_pServerIPLabel = new QLabel(tr("Server IP"));
	m_pServerIP = new QLineEdit;
	m_pPortLabel = new QLabel(tr("Port"));
	m_pPort = new QLineEdit;

	m_pCommType = new QComboBox;
	m_pSerialPortInfo = new QComboBox;
	m_pBaud = new QComboBox;
	m_pDataBit = new QComboBox;
	m_pParity = new QComboBox;
	m_pStopBit = new QComboBox;

	m_pStart = new QPushButton(tr("Start"));

	m_pGroupBoxSerial = new QGroupBox;
	m_pGroupBoxNet = new QGroupBox;
	m_pGroupBoxTimeout = new QGroupBox;

	m_pStackedWidget = new QStackedWidget;

	m_pGLayoutSerial = new QGridLayout;
	m_pGLayoutNet = new QGridLayout;
	m_pGLayoutTimeout = new QGridLayout;
	m_pHLayout = new QHBoxLayout;
	m_pVLayout = new QVBoxLayout;

	m_pCommType->addItem(tr("Serial"));
	m_pCommType->addItem(tr("Net"));

	m_pServerIP->setInputMask("000.000.000.000");

	m_pSerialPortInfo->clear();

	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		m_pSerialPortInfo->addItem(info.portName());
	}

	m_pBaud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
	m_pBaud->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
	m_pBaud->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
	m_pBaud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
	m_pBaud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
	m_pBaud->setCurrentIndex(0);

	m_pDataBit->addItem(QStringLiteral("5"), QSerialPort::Data5);
	m_pDataBit->addItem(QStringLiteral("6"), QSerialPort::Data6);
	m_pDataBit->addItem(QStringLiteral("7"), QSerialPort::Data7);
	m_pDataBit->addItem(QStringLiteral("8"), QSerialPort::Data8);
	m_pDataBit->setCurrentIndex(3);

	m_pParity->addItem(tr("None"), QSerialPort::NoParity);
	m_pParity->addItem(tr("Even"), QSerialPort::EvenParity);
	m_pParity->addItem(tr("Odd"), QSerialPort::OddParity);
	m_pParity->addItem(tr("Mark"), QSerialPort::MarkParity);
	m_pParity->addItem(tr("Space"), QSerialPort::SpaceParity);
	m_pParity->setCurrentIndex(0);

	m_pStopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
	m_pStopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
	m_pStopBit->setCurrentIndex(0);

	m_pHLayout->addWidget(m_pCommTypeLabel);
	m_pHLayout->addWidget(m_pCommType);

	m_pGLayoutSerial->addWidget(m_pSerialPortInfoLabel, 0, 0);
	m_pGLayoutSerial->addWidget(m_pSerialPortInfo, 0, 1);
	m_pGLayoutSerial->addWidget(m_pBaudLabel, 1, 0);
	m_pGLayoutSerial->addWidget(m_pBaud, 1, 1);
	m_pGLayoutSerial->addWidget(m_pDataBitLabel, 2, 0);
	m_pGLayoutSerial->addWidget(m_pDataBit, 2, 1);
	m_pGLayoutSerial->addWidget(m_pParityLabel, 3, 0);
	m_pGLayoutSerial->addWidget(m_pParity, 3, 1);
	m_pGLayoutSerial->addWidget(m_pStopBitLabel, 4, 0);
	m_pGLayoutSerial->addWidget(m_pStopBit, 4, 1);

	m_pGLayoutNet->addWidget(m_pServerIPLabel, 0, 0);
	m_pGLayoutNet->addWidget(m_pServerIP, 0, 1);
	m_pGLayoutNet->addWidget(m_pPortLabel, 1, 0);
	m_pGLayoutNet->addWidget(m_pPort, 1, 1);

	m_pGLayoutTimeout->addWidget(m_pTimeOutLabel, 0, 0);
	m_pGLayoutTimeout->addWidget(m_pTimeOutSpinBox, 0, 1);
	m_pGLayoutTimeout->addWidget(m_pTimeOutUnit, 0, 2);
	m_pGLayoutTimeout->addWidget(m_pSpaceLabel, 1, 0);
	m_pGLayoutTimeout->addWidget(m_pSpaceSpinBox, 1, 1);
	m_pGLayoutTimeout->addWidget(m_pSpaceUnit, 1, 2);

	m_pGroupBoxSerial->setLayout(m_pGLayoutSerial);
	m_pGroupBoxNet->setLayout(m_pGLayoutNet);
	m_pGroupBoxTimeout->setLayout(m_pGLayoutTimeout);

	m_pStackedWidget->addWidget(m_pGroupBoxSerial);
	m_pStackedWidget->addWidget(m_pGroupBoxNet);

	m_pVLayout->addLayout(m_pHLayout);
	m_pVLayout->addWidget(m_pStackedWidget);
	m_pVLayout->addWidget(m_pGroupBoxTimeout);
	m_pVLayout->addWidget(m_pStart);

	this->setLayout(m_pVLayout);

	connect(m_pStart, SIGNAL(clicked()), this, SLOT(slot_Start()));
	connect(m_pCommType, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_commType(int)));
}

CommSet::~CommSet()
{
	delete m_pSerialPortInfoLabel;
	delete m_pBaudLabel;
	delete m_pDataBitLabel;
	delete m_pParityLabel;
	delete m_pStopBitLabel;
	delete m_pSerialPortInfo;
	delete m_pBaud;
	delete m_pDataBit;
	delete m_pParity;
	delete m_pStopBit;
	delete m_pStart;
	delete m_pGLayoutSerial;
	delete m_pVLayout;
}

void CommSet::updateSettings()
{
	currentSettings.name = m_pSerialPortInfo->currentText();
	currentSettings.baudRate = m_pBaud->currentText().toInt();
	currentSettings.dataBits = static_cast<QSerialPort::DataBits>(m_pDataBit->itemData(m_pDataBit->currentIndex()).toInt());
	currentSettings.parity = 'N';
	currentSettings.stopBits = static_cast<QSerialPort::StopBits>(m_pStopBit->itemData(m_pStopBit->currentIndex()).toInt());

	currentSettings.commTimeout = m_pTimeOutSpinBox->value();
	currentSettings.commSpace = m_pSpaceSpinBox->value();
}

void CommSet::slot_Start()
{
	switch (m_pCommType->currentIndex())
	{
	case 0:
		updateSettings();
		accept();
		break;
	case 1:
		break;
	default:
		break;
	}
}

void CommSet::slot_commType(int index)
{
	m_pStackedWidget->setCurrentIndex(index);
}

