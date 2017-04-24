#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMenu>

class MenuBar : public QMenuBar
{
	Q_OBJECT
public:
	MenuBar(QWidget * parent = 0);
	~MenuBar();

signals:
	void signal_setComm();
	void signal_setMapSatellite();
	void signal_setMapHybrid();

private:
	QMenu *m_pMenuSet;
	QMenu *m_pMenuTool;
	QMenu *m_pMenuHelp;
	QMenu *m_pMenuMapSet;

	QAction *m_pMapSet;
	QAction *m_pMapSatellite;
	QAction *m_pMapHybrid;
	QAction *m_pCommSet;
};

#endif // MENUBAR_H
