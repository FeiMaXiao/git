#include "valuectl.h"

ValueCtl::ValueCtl(QString name, QString unit, QWidget *parent) : QWidget(parent)
  , m_pNameLabel(0)
  , m_pUnitLabel(0)
  , m_pValueLineEdit(0)
  , m_pHLayout(0)
{
    m_pNameLabel = new QLabel(name);
    m_pUnitLabel = new QLabel(unit);
    m_pValueLineEdit = new QLineEdit;
    m_pHLayout = new QHBoxLayout;

	m_pValueLineEdit->setFixedSize(90, 30);

    m_pHLayout->addWidget(m_pNameLabel);
    m_pHLayout->addWidget(m_pValueLineEdit);
    m_pHLayout->addWidget(m_pUnitLabel);
    m_pHLayout->addStretch();

    this->setLayout(m_pHLayout);
}

ValueCtl::~ValueCtl()
{
	delete m_pUnitLabel;
	delete m_pValueLineEdit;
	delete m_pNameLabel;
	delete m_pHLayout;
}

void ValueCtl::setValue(double value)
{
    m_pValueLineEdit->setText(QString::number(value));
}

