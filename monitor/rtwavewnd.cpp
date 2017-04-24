#include "rtwavewnd.h"

RtWaveWnd::RtWaveWnd(QWidget *parent) : QwtPlot(parent)
  , m_nMixRange(-100)
  , m_nMaxRange(100)
  , m_pGrid(0)
  , m_pPlotCurve(0)
  , m_pSymbol(0)
{
    plotLayout()->setAlignCanvasToScales(true);
    //this->setCanvasBackground(QColor(29, 100, 141));

    m_pGrid = new QwtPlotGrid();
    m_pGrid->setMajorPen(Qt::gray, 0, Qt::DotLine);
    m_pGrid->attach(this);

    this->setAxisScale(xBottom, m_nMixRange, m_nMaxRange);
    this->setAxisScale(yLeft, m_nMixRange, m_nMaxRange);

    m_pPlotCurve = new QwtPlotCurve();
    m_pPlotCurve->setStyle(QwtPlotCurve::Dots);

    m_pSymbol = new QwtSymbol(QwtSymbol::Ellipse, QBrush(Qt::white), QPen(Qt::white), QSize(3, 3));
    m_pPlotCurve->setSymbol(m_pSymbol);
    m_pPlotCurve->setSamples(m_points);
    m_pPlotCurve->attach(this);

    this->replot();
}

RtWaveWnd::~RtWaveWnd()
{
	delete m_pPlotCurve;
}

