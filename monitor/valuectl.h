#ifndef VALUECTL_H
#define VALUECTL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

class ValueCtl : public QWidget
{
    Q_OBJECT
public:
    explicit ValueCtl(QString name, QString unit, QWidget *parent = 0);
    ~ValueCtl();

    void setValue(double value);

signals:

public slots:

private:
    QLabel *m_pNameLabel;
    QLabel *m_pUnitLabel;

    QLineEdit *m_pValueLineEdit;

    QHBoxLayout *m_pHLayout;
};

#endif // VALUECTL_H
