#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QLabel>
#include "commset.h"

class StatusBar : public QStatusBar
{
	Q_OBJECT
public:
    StatusBar(QWidget *parent = 0);
    ~StatusBar();

public slots:
	void slot_CommState(CommSet::CommState state);
	void slot_CommType(CommSet::CommType type);

private:
	QLabel *m_pCommType;
	QLabel *m_pCommState;
};

#endif // STATUSBAR_H
