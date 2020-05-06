#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>
#include <iostream>
#include <cstdlib>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QDateTime>
#include <QVector>
#include <QDebug>
#include "chart.h"
#include "coolerchart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

    typedef enum
    {
        TC_MODE,
        PC_MODE
    } OPERATIONAL_MODE;

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    float TargetTemperature(void)               { return m_targetTemperature; }
    void TargetTemperature( float f, bool updateDisplay = false );

    float TargetTemperatureBand(void)           { return m_targetTemperatureBand; }
    void TargetTemperatureBand( float f, bool updateDisplay= false );

    float TargetTemperatureBand_Hi(void)        { return m_targetTemperatureBand_Hi; }
    float TargetTemperatureBand_Low(void)       { return m_targetTemperatureBand_Low; }

    float TargetPower(void)                     { return m_targetPower; }
    void TargetPower( float f, bool updateDisplay= false );

private:
    void setupForMode(OPERATIONAL_MODE om);

    CoolerChartTC *TCchart;
    CoolerChart *RTchart;

private slots:
    void on_SoftStop_pressed();
    void on_Deflux_pressed();
    void on_TargetTemperatureSpin_valueChanged(double arg1);
    void on_TemperatureBandSpin_valueChanged(double arg1);
    void on_KISpin_valueChanged(double arg1);
    void on_PowerOutputSpin_valueChanged(double arg1);
    void on_KPSpin_valueChanged(double arg1);
    void on_RTGraphRadioButton_clicked();
    void on_TCGraphRadioButton_clicked();
    void on_TemperatureControlModeRadioButton_clicked();
    void on_PowerControlModeRadioButton_clicked();

    //void on_ledIndicator_0_toggled(bool checked);

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    Ui::Dialog *ui;
    float m_targetTemperature;
    float m_targetTemperatureBand;
    float m_targetTemperatureBand_Hi;
    float m_targetTemperatureBand_Low;
    float m_targetPower;
    int m_timer;
    QDateTime m_startTime;
};
#endif // DIALOG_H
