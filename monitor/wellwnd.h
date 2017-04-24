#ifndef HYDRAULICWND_H
#define HYDRAULICWND_H

#include "minewnd.h"

class WellWnd : public QWidget
{
	Q_OBJECT
public:
	explicit WellWnd(int mineCount, QWidget *parent = 0);
	~WellWnd();

	void showData(int id);
	void setLed(int id);

signals:

	public slots :

private:
	QVector<MineWnd *> m_vecMine;
	QVBoxLayout *m_pVLayout;
	int m_id;
};

#endif // HYDRAULICWND_H
