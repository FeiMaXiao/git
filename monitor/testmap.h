#ifndef TESTMAP_H
#define TESTMAP_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushbutton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class TestMap : public QDialog
{
    Q_OBJECT
public:
    TestMap(QWidget *parent = 0);

signals:
    void signal_latLng(double lat, double lng);
    void signal_clearWp();

public slots:
    void slot_latLng();

private:
    QLabel *m_pLatLabel;
    QLabel *m_pLngLabel;

    QLineEdit *m_pLatLine;
    QLineEdit *m_pLngLine;

    QPushButton *m_pOK;
    QPushButton *m_pNO;
    QPushButton *m_pClear;

    QGridLayout *m_pGLayout;
    QHBoxLayout *m_pHLayout;
    QVBoxLayout *m_pVLayout;
};

#endif // TESTMAP_H
