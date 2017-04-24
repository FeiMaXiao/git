#ifndef PLOTLINES_H
#define PLOTLINES_H
#define QWT_DLL
#include<qwt_plot.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>
#include <qpen.h>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>
#include <QtWidgets/QWidget>

class PlotLines : public QwtPlot
{
     Q_OBJECT
public:
     explicit PlotLines(QWidget *parent = 0);
     QwtPlotCurve *m_pCurve;
     QVector<QPointF>* vecPoint;
     void setData(const QVector<QPointF>& _vecPoint);
     private Q_SLOTS:
     void showItem(const QVariant &itemInfo, bool on);//点击图例，显示相应的曲线
};
#endif // PLOTLINES_H