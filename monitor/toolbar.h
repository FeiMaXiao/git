#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QToolButton>
#include "testmap.h"

class ToolBar : public QToolBar
{
	Q_OBJECT
public:
	explicit ToolBar(QWidget * parent = 0);
	~ToolBar();

signals:
	void signal_testMapLatLng(double lat, double lng);
	void signal_testMapClear();

public slots:
	void slot_testMap();

private:
	QToolButton *m_pToolBtn;
	TestMap *m_pTestMap;
	
};

#endif // TOOLBAR_H
