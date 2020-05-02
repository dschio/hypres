#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <cstdlib>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>


QT_CHARTS_USE_NAMESPACE



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // select default radio buttons
    ui->TCGraphRadioButton->setChecked(true);
    ui->TemperatureControlModeRadioButton->setChecked(true);

    // set up the rest of the window for these settings
    setupForMode(TC_MODE);

    //ui->MyChart->

    QLineSeries *series = new QLineSeries();
    QLineSeries *bandHigh = new QLineSeries();
    QLineSeries *bandLow = new QLineSeries();

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    *bandHigh <<  QPointF(0, 4) << QPointF(20, 4);
    *bandLow << QPointF(0, 2) << QPointF(20, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->addSeries(bandHigh);
    chart->addSeries(bandLow);
    chart->createDefaultAxes();
    chart->setTitle("RT");


//    bandHigh->setPointLabelsVisible(true);    // is false by default
//    bandHigh->setPointLabelsColor(Qt::black);
//    bandHigh->setPointLabelsFormat("@yPoint");

    ui->MyChart->setChart(chart);

    ui->text_RT->display(123.45);

    QPalette *lcdpalette = new QPalette;
    lcdpalette->setColor(QPalette::Background, QColor(255, 255, 255));
    lcdpalette->setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
    ui->text_RT->setPalette(*lcdpalette);
    ui->text_TC->setPalette(*lcdpalette);
    ui->text_POWER->setPalette(*lcdpalette);



}

Dialog::~Dialog()
{
    delete ui;
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
}

void Dialog::on_TemperatureBandSpin_valueChanged(double arg1)
{
    qDebug() << "Temperature band is " << qSetRealNumberPrecision( 10 ) << arg1;
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
}


/////////////////////////////////////////////////////
// select the graph with the following...
void Dialog::on_RTGraphRadioButton_clicked()
{
    qDebug() << "RT Graph";
}

void Dialog::on_TCGraphRadioButton_clicked()
{
    qDebug() << "TC Graph";
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

