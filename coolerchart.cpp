#include "coolerchart.h"

CoolerChart::CoolerChart( QString ChartTitle, QString yAxisTitle, QLineEdit * textBox ) :
    m_accumulatedSamples(0),
    m_prevMax(0)
{
    // set the title
    setTitle( ChartTitle );
    legend()->hide();
    m_textBox = textBox;

    // add in the series
    Series = new  QLineSeries;
    addSeries(Series);

    // add the x and y axis
    Xaxis = new QDateTimeAxis;
    Yaxis = new QValueAxis;

    // format and label for the x
    Xaxis->setFormat("h:mm:ss");
    Xaxis->setTitleText("sample time");

    // label for the y
    Yaxis->setTitleText( yAxisTitle );

    // add them to the chart
    addAxis(Xaxis, Qt::AlignBottom);
    addAxis(Yaxis , Qt::AlignLeft);

    // attach them to the series
    Series->attachAxis(Xaxis);
    Series->attachAxis(Yaxis);

    PointsVector = new QVector<QPointF>;
    PointsVector->clear();

}

CoolerChart::~CoolerChart()
{
    delete PointsVector;
    Series->detachAxis(Yaxis);
    Series->detachAxis(Xaxis);
    removeAxis(Yaxis);
    removeAxis(Xaxis);
    delete Yaxis;
    delete Xaxis;
    removeSeries(Series);
    delete Series;
}

void CoolerChart::Update( float sample )
{
   if( m_accumulatedSamples > TOTAL_SAMPLES )
   {
       // keep adding until full, then start popping off.
       PointsVector->pop_front();
   }

   QDateTime now = QDateTime::currentDateTime();
   qint64 msecs = now.toMSecsSinceEpoch();

   QPointF point;
   point.rx() = msecs;
   point.ry() = sample;

   if( point.ry() > m_prevMax )
       m_prevMax = point.ry();

   PointsVector->push_back( point );

   if( zoomFlag == false )
   {
       Yaxis->setMin(0);
       Yaxis->setMax(m_prevMax);

       // if we haven't gotten enough data yet to fill the graph
       if( now < m_startTime.addSecs(SECONDS_TO_GRAPH) )
       {
            Xaxis->setMin(m_startTime);
            Xaxis->setMax(m_startTime.addSecs(SECONDS_TO_GRAPH));
       }
       else
       {
           QDateTime newStartTime = now.addSecs(-SECONDS_TO_GRAPH);
           Xaxis->setMin(newStartTime);
           Xaxis->setMax(now.addSecs(SECONDS_TO_GRAPH));
       }
   }

    Series->replace(*PointsVector);

    // update the box if there is one
    if( m_textBox )
    {
        QString rt;
        rt.setNum(point.ry(),'f',2);
        m_textBox->setText(rt.rightJustified(8, ' '));
        m_textBox->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
    }
}


CoolerChartTC::CoolerChartTC(QString ChartTitle, QString yAxisTitle,  QLineEdit * textBox) :
    CoolerChart( ChartTitle, yAxisTitle, textBox ),
    m_hi(0),
    m_low(0)
{
    // add in the extra series
    LowSeries = new  QLineSeries;
    addSeries(LowSeries);
    LowSeries->attachAxis(Xaxis);
    LowSeries->attachAxis(Yaxis);

    HiSeries = new  QLineSeries;
    addSeries(HiSeries);
    HiSeries->attachAxis(Xaxis);
    HiSeries->attachAxis(Yaxis);

    LowPointsVector = new QVector<QPointF>;
    LowPointsVector->clear();

    HiPointsVector = new QVector<QPointF>;
    HiPointsVector->clear();
}

void CoolerChartTC::Update(float sample, float low, float high )
{
    CoolerChart::Update(sample);
    if( m_accumulatedSamples > TOTAL_SAMPLES )
    {
        // keep adding until full, then start popping off.
        HiPointsVector->pop_front();
        LowPointsVector->pop_front();
    }

    QDateTime now = QDateTime::currentDateTime();
    qint64 msecs = now.toMSecsSinceEpoch();

    QPointF point;
    point.rx() = msecs;
    point.ry() = low;
    LowPointsVector->push_back( point );

    point.ry() = high;
    HiPointsVector->push_back( point );

    LowSeries->replace(*LowPointsVector);
    HiSeries->replace(*HiPointsVector);

}

CoolerChartTC::~CoolerChartTC()
{
    delete HiPointsVector;
    delete LowPointsVector;

    HiSeries->detachAxis(Yaxis);
    HiSeries->detachAxis(Xaxis);
    delete HiSeries;
    LowSeries->detachAxis(Yaxis);
    LowSeries->detachAxis(Xaxis);
    delete LowSeries;
}
