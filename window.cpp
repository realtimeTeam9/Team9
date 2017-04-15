
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <cmath>

Window::Window() :gain(50), count(0)
{

        thermo = new QwtThermo;
        thermo->setFillBrush( QBrush(Qt::red) );
        thermo->setRange(0, 50);
        thermo->show();


        for( int index=0; index<plotDataSize; ++index )
        {
                xData[index] = index;
                yData[index] = 0;
        }

        curve = new QwtPlotCurve;
        plot = new QwtPlot;
        curve->setSamples(xData, yData, plotDataSize);
        curve->attach(plot);

        plot->replot();
        plot->show();


        vLayout = new QVBoxLayout;
        vLayout->addWidget(thermo);


        hLayout = new QHBoxLayout;
        hLayout->addLayout(vLayout);
        hLayout->addWidget(plot);

        setLayout(hLayout);

}

Window::~Window() {

        }

void Window::timerEvent( QTimerEvent * )
{
         char path[100] = "/sys/bus/w1/devices/28-0416c0917bff/w1_slave";

         char buf[100];

         int fd =-1;

         char *temp;

         float value;

        fd = open(path,O_RDONLY);
        read(fd,buf,sizeof(buf));
        temp = strchr(buf,'t');

        sscanf(temp,"t=%s",temp);

        value = atof(temp)/1000;

        double inVal=(gain/50) * value;

        memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );

        yData[plotDataSize-1] = inVal;

        curve->setSamples(xData, yData, plotDataSize);

        plot->replot();
        
        thermo->setValue( inVal );

} 

 void Window::setGain(double gain)
{
        this->gain = gain;
}

