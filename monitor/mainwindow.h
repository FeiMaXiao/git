#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menubar.h"
#include "toolbar.h"
#include "statusbar.h"
#include "widget.h"
#include "communication.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:

public slots :

private:
	MenuBar *m_pMenuBar;
	ToolBar *m_pToolBar;
	StatusBar *m_pStatusBar;
	Widget *m_pWidget;
	Communication *m_pComm;
};

#endif // MAINWINDOW_H
