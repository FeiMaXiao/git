#include "plotlines.h"
PlotLines::PlotLines(QWidget *parent) :
QwtPlot(parent)
{
     setCanvasBackground(Qt::white);
     m_pCurve = new QwtPlotCurve;
     m_pCurve->attach(this);
     setAxisScale(QwtPlot::xBottom, 0, 60, 5);
     setAxisScale(QwtPlot::yLeft, 0, 100, 10);
     setAxisTitle(QwtPlot::xBottom, tr("时间   /小时"));
     setAxisTitle(QwtPlot::yLeft, "流量   /");
     m_pCurve->setPen(QColor(Qt::red));
     m_pCurve->setStyle(QwtPlotCurve::Lines);
     m_pCurve->setSymbol(new QwtSymbol(QwtSymbol::Cross, Qt::NoBrush,
                                QPen(Qt::black), QSize(5, 5)));
     m_pCurve->setCurveAttribute(QwtPlotCurve::Fitted);
     //m_pCurve->setSamples()
}
//点击图例，显示相应的曲线
void PlotLines::showItem(const QVariant &itemInfo, bool on)
{
     
}
void PlotLines::setData(const QVector<QPointF>& _vecPoint)
{
     m_pCurve->setSamples(_vecPoint);
     this->replot();
	 this->show();
     //m_pCurve->setVisible(false);
}