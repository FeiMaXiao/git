#ifndef WIDGET_H
#define WIDGET_H

#include <QHBoxLayout>
#include "scrolltabctl.h"
#include "rtdatatablewnd.h"
#include "rtwavewnd.h"
#include "giswnd.h"
#include "wellwnd.h"
#include "plotlines.h"

class Widget : public QWidget
{
	Q_OBJECT
public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

signals:


	public slots :
		void slot_setMapSatellite();
	void slot_setMapHybrid();
	void slot_MapCreateWp(double lat, double lng);
	void slot_MapClearWp();
	void slot_wellData(int id);
	void slot_wellState(int id);


private:
	QTabWidget *m_pLeft;
	ScrollTabCtl *m_pRight;

	RtDataTableWnd *m_pDataTable;
	RtWaveWnd *m_pRtWave;
	GisWnd *m_pGis;
	WellWnd *m_pWell;
	PlotLines *m_pPlotLineWnd;

	QHBoxLayout *m_pHLayout;
};

#endif // WIDGET_H
