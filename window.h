#ifndef WINDOW_H
#define WINDOW_H

#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

#include <QBoxLayout>

class Window : public QWidget
{
        Q_OBJECT

public:
        Window();

        ~Window();

        void timerEvent( QTimerEvent * );

 public slots:
        void setGain(double gain);

private:
        QwtThermo    *thermo;
        QwtPlot      *plot;
        QwtPlotCurve *curve;

        QVBoxLayout  *vLayout;
        QHBoxLayout  *hLayout;

        static const int plotDataSize = 100;

        double xData[plotDataSize];
        double yData[plotDataSize];

        double gain;
        int count;

};

#endif
