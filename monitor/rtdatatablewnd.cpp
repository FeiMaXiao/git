#include "rtdatatablewnd.h"

RtDataTableWnd::RtDataTableWnd(int rows, int cols, QStringList hLabel, QWidget *parent) : QWidget(parent)
  , m_pTable(0)
  , m_pVLayout(0)
{
    m_pTable = new QTableWidget(rows, cols);

	if (hLabel.size() == cols)
	{
		m_pTable->setHorizontalHeaderLabels(hLabel);
	}
	
    m_pVLayout = new QVBoxLayout;

	m_pVLayout->setContentsMargins(0, 0, 0, 0);

    m_pVLayout->addWidget(m_pTable);

    this->setLayout(m_pVLayout);
}

RtDataTableWnd::~RtDataTableWnd()
{

}

