#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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

private:
    void setupForMode(OPERATIONAL_MODE om);

private slots:
    void on_SoftStop_pressed();
    void on_TargetTemperatureSpin_valueChanged(double arg1);
    void on_TemperatureBandSpin_valueChanged(double arg1);
    void on_KISpin_valueChanged(double arg1);
    void on_PowerOutputSpin_valueChanged(double arg1);
    void on_KPSpin_valueChanged(double arg1);
    void on_RTGraphRadioButton_clicked();
    void on_TCGraphRadioButton_clicked();
    void on_TemperatureControlModeRadioButton_clicked();
    void on_PowerControlModeRadioButton_clicked();



private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
