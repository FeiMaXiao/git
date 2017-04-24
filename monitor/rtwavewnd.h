#ifndef RTWAVEWND_H
#define RTWAVEWND_H

#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>

class RtWaveWnd : public QwtPlot
{
    Q_OBJECT
public:
    explicit RtWaveWnd(QWidget *parent = 0);
    ~RtWaveWnd();

signals:

public slots:

private:
    QPolygonF m_points;
    QwtPlotGrid *m_pGrid;
    QwtPlotCurve *m_pPlotCurve;
    QwtSymbol *m_pSymbol;

    int m_nMixRange;
    int m_nMaxRange;
};

#endif // RTWAVEWND_H
