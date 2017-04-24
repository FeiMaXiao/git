#ifndef SCROLLTABCTL_H
#define SCROLLTABCTL_H

#include <QTabWidget>
#include <QScrollArea>

class ScrollTabCtl : public QTabWidget
{
public:
    explicit ScrollTabCtl(QWidget *parent = 0);
    ~ScrollTabCtl();
    void addPage(QWidget *widget, QString name);

private:
    QVector<QScrollArea *> m_vecScrollArea;
};

#endif // SCROLLTABCTL_H
