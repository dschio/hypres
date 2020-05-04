#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <cstdlib>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QVector>
#include <QDebug>
#include "chart.h"

QT_CHARTS_USE_NAMESPACE

#define SECONDS_TO_GRAPH    (360)                  // 1 hour graph (10 minutes for test)
#define TOTAL_SAMPLES       (SECONDS_TO_GRAPH*3)    // 3 hours minimum (if sampled 1 per sec)

bool zoomFlag = false;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Cryocooler");

    ///////////////////////////////////////////
    // set up the tip temperature chart
    Chart *TCchart = new Chart();
    TCchart->setTitle("TC");
    TCchart->legend()->hide();
    TCchart->addSeries(TCseries);
    TCchart->addSeries(bandHigh);
    TCchart->addSeries(bandLow);
    TCchart->addSeries(powerTarget);
    // and the axes for it
    TCchart->addAxis(TCaxisX, Qt::AlignBottom);
    TCchart->addAxis(TCaxisY, Qt::AlignLeft);
    TCseries->attachAxis(TCaxisX);
    TCseries->attachAxis(TCaxisY);
    // include the temperature band markers on this chart
    bandHigh->attachAxis(TCaxisX);
    bandHigh->attachAxis(TCaxisY);
    bandLow->attachAxis(TCaxisX);
    bandLow->attachAxis(TCaxisY);
    // set the x axis for the format as shown
    TCaxisX->setFormat("h:mm:ss");
    // x axis label
    TCaxisX->setTitleText("sample time");
    // y axis label
    TCaxisY->setTitleText("\u00B0 K");
    // ticks
    TCaxisX->setTickCount(10);
    // now attach the chart to the display widget
    ui->TC_Chart->setChart(TCchart);

    ///////////////////////////////////////////
    // set up the reject temperature chart
    Chart *RTchart = new Chart();
    RTchart->setTitle("RT");
    RTchart->addSeries(RTseries);
    RTchart->legend()->hide();
    // and the axes for it
    RTchart->addAxis(RTaxisX, Qt::AlignBottom);
    RTchart->addAxis(RTaxisY, Qt::AlignLeft);
    RTseries->attachAxis(RTaxisX);
    RTseries->attachAxis(RTaxisY);
    // set the x axis for the format as shown
    RTaxisX->setFormat("h:mm:ss");
    // x axis label
    RTaxisX->setTitleText("sample time");
    // y axis label
    RTaxisY->setTitleText("\u00B0 K");
    // ticks
    RTaxisX->setTickCount(10);
    // now attach the chart to the display widget
    ui->RT_Chart->setChart(RTchart);


    ///////////////////////////////////////////
    // set up the various other boxes
    //
    // select default radio buttons
    ui->TCGraphRadioButton->setChecked(true);
    ui->TemperatureControlModeRadioButton->setChecked(true);

    // set up some default values (this will probably change)
    TargetTemperature((float)200.0, true);
    TargetTemperatureBand((float)5.0, true);
    TargetPower( (float)100, true );

    ///////////////////////////////////////////
    // start with a default selection of the TC chart
    ui->RT_Chart->hide();
    ui->TC_Chart->show();

    ///////////////////////////////////////////
    // and temperature control mode
    setupForMode(TC_MODE);
    ui->TC_Chart->setFocus();


    ///////////////////////////////////////////
    // save the start time for the graph
    // start time
    m_startTime = QDateTime::currentDateTime();

    // and clear out the accumulated samples
    m_accumulatedSamples = 0;
    TCpointsVector->clear();
    RTpointsVector->clear();
    BandHighpointsVector->clear();
    BandLowpointsVector->clear();
    PowerpointsVector->clear();


    ///////////////////////////////////////////
    // start a timer to simulate the data
    m_timer = startTimer(1000);   // 1-second timer


//    QPalette *lcdpalette = new QPalette;
//    lcdpalette->setColor(QPalette::Background, QColor(255, 255, 255));
//    lcdpalette->setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
//    ui->lcd_text_RT->setDigitCount(6);
//    ui->lcd_text_RT->setSmallDecimalPoint(true);
//    ui->lcd_text_TC->setDigitCount(6);
//    ui->lcd_text_TC->setSmallDecimalPoint(true);
//    ui->lcd_text_RT->setPalette(*lcdpalette);
//    ui->lcd_text_TC->setPalette(*lcdpalette);
//    ui->lcd_text_POWER->setPalette(*lcdpalette);
//    ui->lcd_text_RT->hide();
//    ui->lcd_text_TC->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::TargetTemperature( float f, bool updateDisplay )
{
    m_targetTemperature = f;
    if( updateDisplay )
    {
        ui->TargetTemperatureSpin->setValue(f);
    }
}

void Dialog::TargetTemperatureBand( float f, bool updateDisplay )
{
    m_targetTemperatureBand = f;
    if( updateDisplay )
    {
        ui->TemperatureBandSpin->setValue(f);
    }
}

void Dialog::TargetPower( float f, bool updateDisplay )
{
    m_targetPower = f;
    if( updateDisplay )
    {
        ui->PowerOutputSpin->setValue(f);
    }
}

void Dialog::timerEvent(QTimerEvent *event)
{
    // test data coming in
    static float prevRTMax = 0;
    static float prevTCMax = 0;
    static float prevPowerMax = 0;


    if( event->timerId() != m_timer )
    {
        return;
    }

    if( m_accumulatedSamples > TOTAL_SAMPLES )
    {
        // keep adding until full, then start popping off.
        TCpointsVector->pop_front();
        RTpointsVector->pop_front();
        BandLowpointsVector->pop_front();
        BandHighpointsVector->pop_front();
        PowerpointsVector->pop_front();
    }

    QDateTime now = QDateTime::currentDateTime();
    qint64 msecs = now.toMSecsSinceEpoch();

    // add in the new points
    QPointF TCtestPoint, RTtestPoint, PowerTestPoint;

    // test data
    {
        static int xx = 0;
        TCtestPoint.ry() = 400.0 - ((float)xx / (100.0 + (float)xx) * 200.0);
        RTtestPoint.ry() = ((float)xx / (100.0 + (float)xx) * 200.0);
        PowerTestPoint.ry() = ((float)xx / (70.0 + (float)xx) * 120.0);
        xx++;
    }

    TCtestPoint.rx() = msecs;
    RTtestPoint.rx() = msecs;
    PowerTestPoint.rx() = msecs;

    if( TCtestPoint.ry() > prevTCMax )
        prevTCMax = TCtestPoint.ry();

    if( RTtestPoint.ry() > prevRTMax )
        prevRTMax = RTtestPoint.ry();

    if( PowerTestPoint.ry() > prevPowerMax )
        prevPowerMax = PowerTestPoint.ry();

    TCpointsVector->push_back( TCtestPoint );
    RTpointsVector->push_back( RTtestPoint );

    BandHighpointsVector->push_back( QPointF(msecs, TargetTemperatureBand_Hi()) );
    BandLowpointsVector->push_back( QPointF(msecs, TargetTemperatureBand_Low()) );
    PowerpointsVector->push_back( QPointF(msecs, TargetPower() ) );

    // don't change the plot if zooming in
    if( zoomFlag == false )
    {
        TCaxisY->setMin(0);
        TCaxisY->setMax(prevTCMax);

        RTaxisY->setMin(0);
        RTaxisY->setMax(prevRTMax);

        // if we haven't gotten enough data yet to fill the graph
        if( now < m_startTime.addSecs(SECONDS_TO_GRAPH) )
        {
            TCaxisX->setMin(m_startTime);
            TCaxisX->setMax(m_startTime.addSecs(SECONDS_TO_GRAPH));

            RTaxisX->setMin(m_startTime);
            RTaxisX->setMax(m_startTime.addSecs(SECONDS_TO_GRAPH));
        }
        else
        {
            QDateTime newStartTime = now.addSecs(-SECONDS_TO_GRAPH);
            TCaxisX->setMin(newStartTime);
            TCaxisX->setMax(now.addSecs(SECONDS_TO_GRAPH));

            RTaxisX->setMin(newStartTime);
            RTaxisX->setMax(now.addSecs(SECONDS_TO_GRAPH));
        }

    }

    TCseries->replace(*TCpointsVector);
    RTseries->replace(*RTpointsVector);

    bandHigh->replace(*BandHighpointsVector);
    bandLow->replace(*BandLowpointsVector);
    //powerTarget->replace(*PowerpointsVector);

    // update the boxes
    QString rt;
    rt.setNum(RTtestPoint.ry(),'f',2);
    ui->text_RT->setText(rt.rightJustified(8, ' '));
    ui->text_RT->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
    //ui->lcd_text_RT->display(rt);

    rt.setNum(TCtestPoint.ry(),'f',2);
    ui->text_TC->setText(rt.rightJustified(8, ' '));
    ui->text_TC->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
    //ui->text_TC->display(rt);

    // power
    rt.setNum( PowerTestPoint.ry(), 'f', 2 );
    ui->text_POWER->setText(rt.rightJustified(8, ' '));
    ui->text_POWER->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
}

//void Dialog::timerEvent(QTimerEvent *event)
//{
//    // test data coming in
//    static int x=0;
//    static float prevRTMax = 0;
//    static float prevTCMax = 0;
//    static float prevPowerMax = 0;


//    if( event->timerId() != m_timer )
//    {
//        return;
//    }

//    if( x > TOTAL_SECONDS )
//    {
//        // keep adding until full, then start popping off.
//        TCpointsVector->pop_front();
//        RTpointsVector->pop_front();
//        BandLowpointsVector->pop_front();
//        BandHighpointsVector->pop_front();
//        PowerpointsVector->pop_front();
//    }

//    // add in the new points
//    QPointF TCtestPoint, RTtestPoint, PowerTestPoint;

//    TCtestPoint.ry() = 400.0 - ((float)x / (100.0 + (float)x) * 200.0);
//    RTtestPoint.ry() = ((float)x / (100.0 + (float)x) * 200.0);
//    PowerTestPoint.ry() = ((float)x / (70.0 + (float)x) * 120.0);

//    TCtestPoint.rx() = x;
//    RTtestPoint.rx() = x;
//    PowerTestPoint.rx() = x;

//    if( TCtestPoint.ry() > prevTCMax )
//        prevTCMax = TCtestPoint.ry();

//    if( RTtestPoint.ry() > prevRTMax )
//        prevRTMax = RTtestPoint.ry();

//    if( PowerTestPoint.ry() > prevPowerMax )
//        prevPowerMax = PowerTestPoint.ry();

//    TCpointsVector->push_back( TCtestPoint );
//    RTpointsVector->push_back( RTtestPoint );

//    //qDebug() << "pushed " << RTtestPoint << "max " << prevRTMax;
//    //qDebug() << "zoom flag " << zoomFlag;

//    BandHighpointsVector->push_back( QPointF(x, TargetTemperatureBand_Hi()) );
//    BandLowpointsVector->push_back( QPointF(x, TargetTemperatureBand_Low()) );
//    PowerpointsVector->push_back( QPointF(x, TargetPower() ) );

//    // don't change the plot if zooming in
//    if( zoomFlag == false )
//    {
//        TCaxisY->setMin(0);
//        TCaxisY->setMax(prevTCMax);

//        RTaxisY->setMin(0);
//        RTaxisY->setMax(prevRTMax);

//        // if we haven't gotten enough data yet to fill the graph
//        if( x < SECONDS_TO_GRAPH )
//        {
//            TCaxisX->setMin(0);
//            TCaxisX->setMax(SECONDS_TO_GRAPH);

//            RTaxisX->setMin(0);
//            RTaxisX->setMax(SECONDS_TO_GRAPH);
//        }
//        else
//        {
//            int newStart = x - SECONDS_TO_GRAPH;
//            TCaxisX->setMin(newStart);
//            TCaxisX->setMax(SECONDS_TO_GRAPH + newStart);

//            RTaxisX->setMin(newStart);
//            RTaxisX->setMax(SECONDS_TO_GRAPH + newStart);
//        }

//    }

//    TCseries->replace(*TCpointsVector);
//    RTseries->replace(*RTpointsVector);

//    bandHigh->replace(*BandHighpointsVector);
//    bandLow->replace(*BandLowpointsVector);
//    //powerTarget->replace(*PowerpointsVector);

//    // update the boxes
//    QString rt;
//    rt.setNum(RTtestPoint.ry(),'f',2);
//    ui->text_RT->setText(rt.rightJustified(8, ' '));
//    ui->text_RT->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
//    //ui->lcd_text_RT->display(rt);

//    rt.setNum(TCtestPoint.ry(),'f',2);
//    ui->text_TC->setText(rt.rightJustified(8, ' '));
//    ui->text_TC->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
//    //ui->text_TC->display(rt);


//    // power
//    rt.setNum( PowerTestPoint.ry(), 'f', 2 );
//    ui->text_POWER->setText(rt.rightJustified(8, ' '));
//    ui->text_POWER->setAlignment(Qt::AlignRight | Qt::AlignVCenter );

//    x++;
//}

void Dialog::setupForMode( OPERATIONAL_MODE om )
{
    if( om == TC_MODE )
    {
        ui->TargetTemperatureSpin->setVisible(true);
        ui->TargetTemperatureText->setVisible(true);
        ui->TemperatureBandSpin->setVisible(true);
        ui->TemperatureBandText->setVisible(true);
        ui->KISpin->setVisible(true);
        ui->KIText->setVisible(true);
        ui->KPSpin->setVisible(true);
        ui->KPText->setVisible(true);

        ui->PowerOutputSpin->setVisible(false);
        ui->PowerOutputText->setVisible(false);

        //powerTarget->setVisible(false);
        bandHigh->setVisible(true);
        bandLow->setVisible(true);
    }
    else
    {
        ui->TargetTemperatureSpin->setVisible(false);
        ui->TargetTemperatureText->setVisible(false);
        ui->TemperatureBandSpin->setVisible(false);
        ui->TemperatureBandText->setVisible(false);
        ui->KISpin->setVisible(false);
        ui->KIText->setVisible(false);
        ui->KPSpin->setVisible(false);
        ui->KPText->setVisible(false);

        ui->PowerOutputSpin->setVisible(true);
        ui->PowerOutputText->setVisible(true);

        //powerTarget->setVisible(true);
        bandHigh->setVisible(false);
        bandLow->setVisible(false);
    }
}

// these are the widgit handlers.  I used a brute-force approach
// with individual slots because there aren't enough to get
// clever with.

/////////////////////////////////////////////////////
// select target temperature and band with the following..
void Dialog::on_TargetTemperatureSpin_valueChanged(double arg1)
{
    qDebug() << "Target temperature is " << qSetRealNumberPrecision( 10 ) << arg1;

    // get the target temp and save  it
    TargetTemperature( arg1 );

    // also change the temperature band markers on the graph
    m_targetTemperatureBand_Hi = TargetTemperature() + (m_targetTemperatureBand / 2.0);
    m_targetTemperatureBand_Low = TargetTemperature() - (m_targetTemperatureBand / 2.0);
}

void Dialog::on_TemperatureBandSpin_valueChanged(double arg1)
{
    qDebug() << "Temperature band is " << qSetRealNumberPrecision( 10 ) << arg1;
    TargetTemperatureBand( arg1 );

    // also change the temperature band markers on the graph
    m_targetTemperatureBand_Hi = TargetTemperature() + (m_targetTemperatureBand / 2.0);
    m_targetTemperatureBand_Low = TargetTemperature() - (m_targetTemperatureBand / 2.0);
}

/////////////////////////////////////////////////////
// KI and KP with the following...
void Dialog::on_KISpin_valueChanged(double arg1)
{
    qDebug() << "KI is " << qSetRealNumberPrecision( 10 ) << arg1;
}

void Dialog::on_KPSpin_valueChanged(double arg1)
{
    qDebug() << "KP is " << qSetRealNumberPrecision( 10 ) << arg1;
}

/////////////////////////////////////////////////////
// select power output with the following...
void Dialog::on_PowerOutputSpin_valueChanged(double arg1)
{
    qDebug() << "Power Output is " << qSetRealNumberPrecision( 10 ) << arg1;

    TargetPower( arg1 );
}


/////////////////////////////////////////////////////
// select the graph with the following...
void Dialog::on_RTGraphRadioButton_clicked()
{
    qDebug() << "RT Graph";

    ui->RT_Chart->show();
    ui->TC_Chart->hide();
    ui->RT_Chart->setFocus();
    zoomFlag = false;
}

void Dialog::on_TCGraphRadioButton_clicked()
{
    qDebug() << "TC Graph";
    ui->RT_Chart->hide();
    ui->TC_Chart->show();
    ui->TC_Chart->setFocus();
    zoomFlag = false;
}

/////////////////////////////////////////////////////
// select the control mode with the following...
void Dialog::on_TemperatureControlModeRadioButton_clicked()
{
    qDebug() << "TC mode select";
    setupForMode(TC_MODE);
}

void Dialog::on_PowerControlModeRadioButton_clicked()
{
    qDebug() << "PC mode select";
    setupForMode(PC_MODE);
}


/////////////////////////////////////////////////////
// soft stop
void Dialog::on_SoftStop_pressed()
{
    qDebug() << "pressed soft stop";
}

