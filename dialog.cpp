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
#include <QMessageBox>
#include <QAction>
#include "chart.h"
#include "coolerchart.h"
#include "qledindicator.h"

QT_CHARTS_USE_NAMESPACE

bool zoomFlag = false;



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ///////////////////////////////////////////
    // window
    setWindowTitle("Cryocooler");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QDateTime now = QDateTime::currentDateTime();
    ///////////////////////////////////////////
    // set up the tip temperature chart
    TCchart = new CoolerChartTC("TC", "\u00B0 K", ui->text_TC);
    TCchart->SetStartTime(now);
    ui->TC_Chart->setChart(TCchart);

    ///////////////////////////////////////////
    // set up the reject temperature chart
    RTchart = new CoolerChart("RT", "\u00B0 C", ui->text_RT);
    RTchart->SetStartTime(now);
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
    m_startTime = now;

    ///////////////////////////////////////////
    // start a timer to simulate the data
    m_timer = startTimer(1000);   // 1-second timer


    // init the led indicators
    ui->ledIndicator_Connection->SetOff();
    ui->ledIndicator_Error->SetOff();
    ui->ledIndicator_Activity->SetOff();

    // and init the state of the soft start / stop button.
    // assume stopped for now ... will be updated by the
    // control thread.
    ui->ledIndicator_Started->SetGreen();
    ui->ledIndicator_Stopped->SetOff();
    ui->SoftStop->setText("Soft Stop");

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
    if( event->timerId() != m_timer )
    {
        return;
    }

    /////////////////////////////
    // generate simulated test data
    QPointF testPoint;

    static int xx = 0;


//    if(xx&1)
//    {
        ui->ledIndicator_Connection->SetGreen();
//    }
//    else
//    {
//        ui->ledIndicator_Connection->SetRed();
//    }
    ui->ledIndicator_Activity->FlashGreen();
    //ui->ledIndicator_Connection->repaint();


    testPoint.ry() = 400.0 - ((float)xx / (100.0 + (float)xx) * 200.0);
    TCchart->Update(testPoint.ry(), m_targetTemperatureBand_Low, m_targetTemperatureBand_Hi);

    testPoint.ry() = ((float)xx / (100.0 + (float)xx) * 200.0);
    RTchart->Update(testPoint.ry() );

    testPoint.ry() = ((float)xx / (70.0 + (float)xx) * 120.0);
    xx++;

    // power
    QString rt;
    rt.setNum( testPoint.ry(), 'f', 2 );
    ui->text_POWER->setText(rt.rightJustified(8, ' '));
    ui->text_POWER->setAlignment(Qt::AlignRight | Qt::AlignVCenter );

        update();
}

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
    static int xx=0;
    if(xx == 0)
    {
        xx = 1;
        ui->ledIndicator_Started->SetGreen();
        ui->ledIndicator_Stopped->SetOff();
        ui->SoftStop->setText("Soft Stop");
    }
    else
    {
        xx =0;
        ui->ledIndicator_Started->SetOff();
        ui->ledIndicator_Stopped->SetRed();
        ui->SoftStop->setText("Soft Start");
    }
    repaint();
}

void Dialog::on_Deflux_pressed()
{
    qDebug() << "deflux";
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Deflux", "Are you sure you want to deflux the system?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
      qDebug() << "Yes was clicked";
    }
    else
    {
      qDebug() << "Yes was *not* clicked";
    }
}

//void Dialog::on_ledIndicator_0_toggled(bool checked)
//{
//    qDebug() << "Led toggled: " << checked;
//}
