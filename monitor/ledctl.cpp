#include "ledctl.h"

LedCtl::LedCtl(QString name, QWidget *parent) : QWidget(parent)
  , m_pNameLabel(0)
  , m_pImageLabel(0)
  , m_pVLayout(0)

{
    m_pNameLabel = new QLabel(name);
    m_pImageLabel = new QLabel;
    m_pVLayout = new QVBoxLayout;
	m_pVLayout->setAlignment(Qt::AlignCenter);

	setLed(true);

    m_pVLayout->addWidget(m_pNameLabel);
    m_pVLayout->addWidget(m_pImageLabel);
    m_pVLayout->addStretch();

    this->setLayout(m_pVLayout);
}

LedCtl::~LedCtl()
{
    delete m_pImageLabel;
    delete m_pNameLabel;
    delete m_pVLayout;
}

void LedCtl::setLed(bool bl)
{
    if (bl)
    {
        m_pImageLabel->setPixmap(QPixmap("./image/green.png"));
    }
    else
    {
        m_pImageLabel->setPixmap(QPixmap("./image/led.png"));
    }

}

