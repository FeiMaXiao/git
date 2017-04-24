#ifndef MINEWND_H
#define MINEWND_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QGridLayout>
#include "valuectl.h"
#include "ledctl.h"

class MineWnd : public QWidget
{
    Q_OBJECT

public:
	typedef enum
	{
		Start = 0,
		Stop,
		TeleAllow,
		TeleBan
	}PumpState;

	typedef enum
	{
		Run = 0,
		Hitch,
		Alarm
	}Led;

	typedef enum
	{
		VoltageValue = 0,
		CurrentValue,
		InstantFlux,
		CountFlux,
		LevelValue
	}ValueShow;

public:
	explicit MineWnd(unsigned char id, QString title, QWidget *parent = 0);
    ~MineWnd();

	QSize sizeHint() const;

    void setVoltageValue(double value);
    void setCurrentValue(double value);
    void setInstantFlux(double value);
    void setCountFlux(double value);
    void setLevelValue(double value);

    void setRunLed(bool bl);
    void setHitchLed(bool bl);
    void setAlarmLed(bool bl);

	void setLed(Led led, bool bl);

signals:
	void checkBoxCahanged(int);
public slots:
    void slot_telecontrol();
    void slot_startStop();

private:
	unsigned char m_id;

	QCheckBox *m_pTitle;

	QLabel *m_pVoltageValueName;
	QLabel *m_pVoltageValueUnit;
	QLabel *m_pCurrentValueName;
	QLabel *m_pCurrentValueUnit;
	QLabel *m_pInstantFluxName;
	QLabel *m_pInstantFluxUnit;
	QLabel *m_pCountFluxName;
	QLabel *m_pCountFluxUnit;
	QLabel *m_pLevelValueName;
	QLabel *m_pLevelValueUnit;

	QLineEdit *m_pVoltageValue;
	QLineEdit *m_pCurrentValue;
	QLineEdit *m_pInstantFlux;
	QLineEdit *m_pCountFlux;
	QLineEdit *m_pLevelValue;


	QLabel *m_pPumpRunName;
	QLabel *m_pPumpHitchName;
	QLabel *m_pPumpAlarmName;

	QLabel *m_pPumpRunImage;
	QLabel *m_pPumpHitchImage;
	QLabel *m_pPumpAlarmImage;

	QGroupBox *m_pGroupBox;

    QPushButton *m_pTelecontrol;
    QPushButton *m_pStartStop;

    QGridLayout *m_pGLayout;
	QHBoxLayout *m_pHLayoutTitle;
	QGridLayout *m_pGLayoutLed;
    QHBoxLayout *m_pHLayoutButton;
    QVBoxLayout *m_pVLayout;
    QVBoxLayout *m_pVLayoutMain;

	PumpState m_startStop;
	PumpState m_teleControl;
};

#endif // MINEWND_H
