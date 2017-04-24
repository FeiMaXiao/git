#ifndef COMMSET_H
#define COMMSET_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSerialPort>
#include <QStackedWidget>
#include <QSpinBox>

class CommSet : public QDialog
{
	Q_OBJECT
public:
	typedef enum{
		Serial = 0,
		Net
	}CommType;

	typedef enum{
		Connect = 0,
		Disconnect,
		Error
	}CommState;

	typedef struct{
		QString name;
		int baudRate;
		int dataBits;
		char parity;
		int stopBits;

		int commTimeout;
		int commSpace;
	}Settings;

	CommSet(QWidget *parent = 0);
	~CommSet();
	void updateSettings();

	Settings currentSettings;

	public slots:
	void slot_Start();
	void slot_commType(int index);

private:
	QLabel *m_pCommTypeLabel;
	QLabel *m_pSerialPortInfoLabel;
	QLabel *m_pBaudLabel;
	QLabel *m_pDataBitLabel;
	QLabel *m_pParityLabel;
	QLabel *m_pStopBitLabel;

	QLabel *m_pTimeOutLabel;
	QLabel *m_pSpaceLabel;

	QLabel *m_pTimeOutUnit;
	QLabel *m_pSpaceUnit;

	QSpinBox *m_pTimeOutSpinBox;
	QSpinBox *m_pSpaceSpinBox;

	QComboBox *m_pCommType;
	QComboBox *m_pSerialPortInfo;
	QComboBox *m_pBaud;
	QComboBox *m_pDataBit;
	QComboBox *m_pParity;
	QComboBox *m_pStopBit;

	QPushButton *m_pStart;

	QLabel *m_pServerIPLabel;
	QLineEdit *m_pServerIP;
	QLabel *m_pPortLabel;
	QLineEdit *m_pPort;

	QGroupBox *m_pGroupBoxSerial;
	QGroupBox *m_pGroupBoxNet;
	QGroupBox *m_pGroupBoxTimeout;

	QStackedWidget *m_pStackedWidget;

	QGridLayout *m_pGLayoutSerial;
	QGridLayout *m_pGLayoutNet;
	QGridLayout *m_pGLayoutTimeout;
	QHBoxLayout *m_pHLayout;
	QVBoxLayout *m_pVLayout;
};

#endif // COMMSET_H
