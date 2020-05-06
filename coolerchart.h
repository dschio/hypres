#ifndef COOLERCHART_H
#define COOLERCHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QLineEdit>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QDateTime>
#include <QVector>
#include <QDebug>
#include "chart.h"

#define SECONDS_TO_GRAPH    (360)                   // 1 hour graph (10 minutes for test)
#define TOTAL_SAMPLES       (SECONDS_TO_GRAPH*3)    // 3 hours minimum (if sampled 1 per sec)

extern bool zoomFlag;

class CoolerChart : public Chart
{
public:
    CoolerChart( QString title, QString yAxisTitle, QLineEdit * textBox );
    virtual ~CoolerChart();

    void SetStartTime( QDateTime startTime ) { m_startTime = startTime; }
    virtual void Update( float sample );

protected:
    // the charts used here all have the following...
    //Chart Chart;
    QLineSeries *Series;
    QValueAxis  *Yaxis;
    QDateTimeAxis  *Xaxis;
    QVector<QPointF> *PointsVector;
    int m_accumulatedSamples;
    float m_prevMax;
    QDateTime m_startTime;

    // pointer to associated text box if there is one
    QLineEdit * m_textBox;
};


// derives from above, but adds the band markers
class CoolerChartTC : public CoolerChart
{
public:
    CoolerChartTC(QString title, QString yAxisTitle,  QLineEdit * textBox);
    ~CoolerChartTC();
    virtual void Update( float sample, float low, float high );
    void SetBand( float low, float hi ) { m_low = low; m_hi = hi; }

private:
    QLineSeries *LowSeries;
    QVector<QPointF> *LowPointsVector;
    QLineSeries *HiSeries;
    QVector<QPointF> *HiPointsVector;
    float m_hi;
    float m_low;
};

#endif // COOLERCHART_H
