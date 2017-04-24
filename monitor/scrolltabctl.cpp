#include "scrolltabctl.h"

ScrollTabCtl::ScrollTabCtl(QWidget *parent) : QTabWidget(parent)
{
    this->setTabPosition(QTabWidget::South);
}

ScrollTabCtl::~ScrollTabCtl()
{
    for (int i=0; i<m_vecScrollArea.size(); ++i)
    {
        delete m_vecScrollArea.at(i);
    }
}

void ScrollTabCtl::addPage(QWidget *widget, QString name)
{
    QScrollArea *pScroll = new QScrollArea;
	pScroll->setAlignment(Qt::AlignCenter);
    pScroll->setWidget(widget);
    this->addTab(pScroll, name);
    m_vecScrollArea.append(pScroll);
}

