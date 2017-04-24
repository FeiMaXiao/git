#include "testmap.h"

TestMap::TestMap(QWidget *parent) : QDialog(parent)
{
	this->setWindowTitle(tr("Test Map"));

    m_pLatLabel = new QLabel(tr("Lat"));
    m_pLngLabel = new QLabel(tr("Lng"));

    m_pLatLine = new QLineEdit;
    m_pLngLine = new QLineEdit;

    m_pOK = new QPushButton(tr("OK"));
    m_pNO = new QPushButton(tr("NO"));
    m_pClear = new QPushButton(tr("Clear"));

    m_pGLayout = new QGridLayout;
    m_pHLayout = new QHBoxLayout;
    m_pVLayout = new QVBoxLayout;

    m_pGLayout->addWidget(m_pLatLabel, 0, 0);
    m_pGLayout->addWidget(m_pLatLine, 0, 1);
    m_pGLayout->addWidget(m_pLngLabel, 1, 0);
    m_pGLayout->addWidget(m_pLngLine, 1, 1);

    m_pHLayout->addWidget(m_pOK);
    m_pHLayout->addWidget(m_pNO);
    m_pHLayout->addWidget(m_pClear);

    m_pVLayout->addLayout(m_pGLayout);
    m_pVLayout->addLayout(m_pHLayout);

    this->setLayout(m_pVLayout);

    connect(m_pOK, SIGNAL(clicked()), this, SLOT(slot_latLng()));
    connect(m_pNO, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_pClear, SIGNAL(clicked()), this, SIGNAL(signal_clearWp()));
}

void TestMap::slot_latLng()
{
    if (!m_pLatLine->text().isEmpty() && !m_pLngLine->text().isEmpty())
    {
        emit signal_latLng(m_pLatLine->text().toDouble(), m_pLngLine->text().toDouble());
    }
}

