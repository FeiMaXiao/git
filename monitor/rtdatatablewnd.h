#ifndef DATATABLEWND_H
#define DATATABLEWND_H

#include <QTableWidget>
#include <QVBoxLayout>

class RtDataTableWnd : public QWidget
{
    Q_OBJECT
public:
    explicit RtDataTableWnd(int rows, int cols, QStringList hLabel, QWidget *parent = 0);
    ~RtDataTableWnd();

signals:

public slots:

private:
    QTableWidget *m_pTable;
    QVBoxLayout *m_pVLayout;
};

#endif // DATATABLEWND_H
