#ifndef LEDWND_H
#define LEDWND_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class LedCtl : public QWidget
{
    Q_OBJECT
public:
    explicit LedCtl(QString name, QWidget *parent = 0);
    ~LedCtl();
    void setLed(bool bl);

signals:

public slots:

private:
    QLabel *m_pNameLabel;
    QLabel *m_pImageLabel;
	QVBoxLayout *m_pVLayout;
};

#endif // LEDWND_H
