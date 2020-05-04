/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <chartview.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    ChartView *TC_Chart;
    QRadioButton *RTGraphRadioButton;
    QRadioButton *TCGraphRadioButton;
    QLCDNumber *lcd_text_RT;
    QLineEdit *lineEdit;
    QLCDNumber *lcd_text_TC;
    QLineEdit *lineEdit_2;
    QLCDNumber *lcd_text_POWER;
    QLineEdit *lineEdit_3;
    QRadioButton *TemperatureControlModeRadioButton;
    QRadioButton *PowerControlModeRadioButton;
    QLineEdit *TargetTemperatureText;
    QPushButton *SoftStop;
    QLineEdit *PowerOutputText;
    QLineEdit *TemperatureBandText;
    QLineEdit *KPText;
    QLineEdit *KIText;
    QDoubleSpinBox *TargetTemperatureSpin;
    QDoubleSpinBox *TemperatureBandSpin;
    QDoubleSpinBox *KPSpin;
    QDoubleSpinBox *KISpin;
    QDoubleSpinBox *PowerOutputSpin;
    QGroupBox *groupBox;
    ChartView *RT_Chart;
    QTextEdit *text_TC;
    QTextEdit *text_POWER;
    QLineEdit *text_RT;
    QButtonGroup *buttonGroupGraphSelect;
    QButtonGroup *buttonGroupModeSelect;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1140, 691);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(0, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        Dialog->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Dialog->setFont(font);
        Dialog->setAutoFillBackground(true);
        TC_Chart = new ChartView(Dialog);
        TC_Chart->setObjectName(QString::fromUtf8("TC_Chart"));
        TC_Chart->setGeometry(QRect(20, 10, 800, 611));
        TC_Chart->setFrameShape(QFrame::Box);
        TC_Chart->setFrameShadow(QFrame::Plain);
        TC_Chart->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        TC_Chart->setDragMode(QGraphicsView::NoDrag);
        RTGraphRadioButton = new QRadioButton(Dialog);
        buttonGroupGraphSelect = new QButtonGroup(Dialog);
        buttonGroupGraphSelect->setObjectName(QString::fromUtf8("buttonGroupGraphSelect"));
        buttonGroupGraphSelect->addButton(RTGraphRadioButton);
        RTGraphRadioButton->setObjectName(QString::fromUtf8("RTGraphRadioButton"));
        RTGraphRadioButton->setGeometry(QRect(410, 630, 71, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        RTGraphRadioButton->setFont(font1);
        TCGraphRadioButton = new QRadioButton(Dialog);
        buttonGroupGraphSelect->addButton(TCGraphRadioButton);
        TCGraphRadioButton->setObjectName(QString::fromUtf8("TCGraphRadioButton"));
        TCGraphRadioButton->setGeometry(QRect(340, 640, 61, 21));
        TCGraphRadioButton->setFont(font1);
        lcd_text_RT = new QLCDNumber(Dialog);
        lcd_text_RT->setObjectName(QString::fromUtf8("lcd_text_RT"));
        lcd_text_RT->setEnabled(true);
        lcd_text_RT->setGeometry(QRect(950, 30, 141, 51));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        lcd_text_RT->setFont(font2);
        lcd_text_RT->setAutoFillBackground(true);
        lcd_text_RT->setFrameShape(QFrame::WinPanel);
        lcd_text_RT->setFrameShadow(QFrame::Sunken);
        lcd_text_RT->setLineWidth(1);
        lcd_text_RT->setSmallDecimalPoint(false);
        lcd_text_RT->setDigitCount(6);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(850, 30, 91, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        lineEdit->setPalette(palette1);
        QFont font3;
        font3.setPointSize(19);
        lineEdit->setFont(font3);
        lineEdit->setAutoFillBackground(true);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lcd_text_TC = new QLCDNumber(Dialog);
        lcd_text_TC->setObjectName(QString::fromUtf8("lcd_text_TC"));
        lcd_text_TC->setEnabled(true);
        lcd_text_TC->setGeometry(QRect(950, 90, 141, 51));
        lcd_text_TC->setFont(font2);
        lcd_text_TC->setAutoFillBackground(true);
        lcd_text_TC->setFrameShape(QFrame::WinPanel);
        lcd_text_TC->setFrameShadow(QFrame::Sunken);
        lcd_text_TC->setLineWidth(1);
        lcd_text_TC->setSmallDecimalPoint(false);
        lcd_text_TC->setDigitCount(6);
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(850, 90, 91, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        lineEdit_2->setPalette(palette2);
        lineEdit_2->setFont(font3);
        lineEdit_2->setAutoFillBackground(true);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lcd_text_POWER = new QLCDNumber(Dialog);
        lcd_text_POWER->setObjectName(QString::fromUtf8("lcd_text_POWER"));
        lcd_text_POWER->setEnabled(true);
        lcd_text_POWER->setGeometry(QRect(950, 150, 141, 51));
        lcd_text_POWER->setFont(font2);
        lcd_text_POWER->setAutoFillBackground(true);
        lcd_text_POWER->setFrameShape(QFrame::WinPanel);
        lcd_text_POWER->setFrameShadow(QFrame::Sunken);
        lcd_text_POWER->setLineWidth(1);
        lcd_text_POWER->setSmallDecimalPoint(false);
        lcd_text_POWER->setDigitCount(6);
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(850, 150, 91, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        lineEdit_3->setPalette(palette3);
        lineEdit_3->setFont(font3);
        lineEdit_3->setAutoFillBackground(true);
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TemperatureControlModeRadioButton = new QRadioButton(Dialog);
        buttonGroupModeSelect = new QButtonGroup(Dialog);
        buttonGroupModeSelect->setObjectName(QString::fromUtf8("buttonGroupModeSelect"));
        buttonGroupModeSelect->addButton(TemperatureControlModeRadioButton);
        TemperatureControlModeRadioButton->setObjectName(QString::fromUtf8("TemperatureControlModeRadioButton"));
        TemperatureControlModeRadioButton->setGeometry(QRect(870, 280, 251, 17));
        QFont font4;
        font4.setPointSize(11);
        TemperatureControlModeRadioButton->setFont(font4);
        PowerControlModeRadioButton = new QRadioButton(Dialog);
        buttonGroupModeSelect->addButton(PowerControlModeRadioButton);
        PowerControlModeRadioButton->setObjectName(QString::fromUtf8("PowerControlModeRadioButton"));
        PowerControlModeRadioButton->setGeometry(QRect(870, 300, 231, 17));
        PowerControlModeRadioButton->setFont(font4);
        TargetTemperatureText = new QLineEdit(Dialog);
        TargetTemperatureText->setObjectName(QString::fromUtf8("TargetTemperatureText"));
        TargetTemperatureText->setEnabled(false);
        TargetTemperatureText->setGeometry(QRect(840, 330, 160, 51));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        TargetTemperatureText->setPalette(palette4);
        TargetTemperatureText->setFont(font4);
        TargetTemperatureText->setAutoFillBackground(true);
        TargetTemperatureText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SoftStop = new QPushButton(Dialog);
        SoftStop->setObjectName(QString::fromUtf8("SoftStop"));
        SoftStop->setGeometry(QRect(990, 630, 121, 41));
        QFont font5;
        font5.setPointSize(12);
        SoftStop->setFont(font5);
        SoftStop->setAutoDefault(false);
        PowerOutputText = new QLineEdit(Dialog);
        PowerOutputText->setObjectName(QString::fromUtf8("PowerOutputText"));
        PowerOutputText->setEnabled(false);
        PowerOutputText->setGeometry(QRect(840, 330, 160, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        PowerOutputText->setPalette(palette5);
        PowerOutputText->setFont(font4);
        PowerOutputText->setAutoFillBackground(true);
        PowerOutputText->setCursorPosition(12);
        PowerOutputText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TemperatureBandText = new QLineEdit(Dialog);
        TemperatureBandText->setObjectName(QString::fromUtf8("TemperatureBandText"));
        TemperatureBandText->setEnabled(false);
        TemperatureBandText->setGeometry(QRect(840, 390, 160, 51));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        TemperatureBandText->setPalette(palette6);
        TemperatureBandText->setFont(font4);
        TemperatureBandText->setAutoFillBackground(true);
        TemperatureBandText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        KPText = new QLineEdit(Dialog);
        KPText->setObjectName(QString::fromUtf8("KPText"));
        KPText->setEnabled(false);
        KPText->setGeometry(QRect(840, 460, 160, 51));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        KPText->setPalette(palette7);
        KPText->setFont(font4);
        KPText->setAutoFillBackground(true);
        KPText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        KIText = new QLineEdit(Dialog);
        KIText->setObjectName(QString::fromUtf8("KIText"));
        KIText->setEnabled(false);
        KIText->setGeometry(QRect(840, 520, 160, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        KIText->setPalette(palette8);
        KIText->setFont(font4);
        KIText->setAutoFillBackground(true);
        KIText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TargetTemperatureSpin = new QDoubleSpinBox(Dialog);
        TargetTemperatureSpin->setObjectName(QString::fromUtf8("TargetTemperatureSpin"));
        TargetTemperatureSpin->setGeometry(QRect(1005, 330, 125, 51));
        TargetTemperatureSpin->setFont(font4);
        TargetTemperatureSpin->setKeyboardTracking(false);
        TargetTemperatureSpin->setDecimals(2);
        TargetTemperatureSpin->setMaximum(999.990000000000009);
        TargetTemperatureSpin->setSingleStep(1.000000000000000);
        TemperatureBandSpin = new QDoubleSpinBox(Dialog);
        TemperatureBandSpin->setObjectName(QString::fromUtf8("TemperatureBandSpin"));
        TemperatureBandSpin->setGeometry(QRect(1005, 390, 125, 51));
        TemperatureBandSpin->setFont(font4);
        TemperatureBandSpin->setKeyboardTracking(false);
        TemperatureBandSpin->setDecimals(2);
        TemperatureBandSpin->setMaximum(999.990000000000009);
        TemperatureBandSpin->setSingleStep(0.100000000000000);
        TemperatureBandSpin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        KPSpin = new QDoubleSpinBox(Dialog);
        KPSpin->setObjectName(QString::fromUtf8("KPSpin"));
        KPSpin->setGeometry(QRect(1005, 460, 125, 51));
        KPSpin->setFont(font4);
        KPSpin->setKeyboardTracking(false);
        KPSpin->setDecimals(5);
        KPSpin->setMaximum(999.999990000000025);
        KPSpin->setSingleStep(1.000000000000000);
        KISpin = new QDoubleSpinBox(Dialog);
        KISpin->setObjectName(QString::fromUtf8("KISpin"));
        KISpin->setGeometry(QRect(1005, 520, 125, 51));
        KISpin->setFont(font4);
        KISpin->setKeyboardTracking(false);
        KISpin->setDecimals(5);
        KISpin->setMaximum(999.999990000000025);
        KISpin->setSingleStep(0.100000000000000);
        PowerOutputSpin = new QDoubleSpinBox(Dialog);
        PowerOutputSpin->setObjectName(QString::fromUtf8("PowerOutputSpin"));
        PowerOutputSpin->setGeometry(QRect(1005, 330, 125, 51));
        PowerOutputSpin->setFont(font4);
        PowerOutputSpin->setKeyboardTracking(false);
        PowerOutputSpin->setDecimals(2);
        PowerOutputSpin->setMaximum(999.990000000000009);
        PowerOutputSpin->setSingleStep(1.000000000000000);
        PowerOutputSpin->setStepType(QAbstractSpinBox::DefaultStepType);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(830, 259, 301, 331));
        groupBox->setFlat(false);
        RT_Chart = new ChartView(Dialog);
        RT_Chart->setObjectName(QString::fromUtf8("RT_Chart"));
        RT_Chart->setGeometry(QRect(20, 10, 801, 611));
        text_TC = new QTextEdit(Dialog);
        text_TC->setObjectName(QString::fromUtf8("text_TC"));
        text_TC->setGeometry(QRect(950, 90, 141, 51));
        QFont font6;
        font6.setPointSize(24);
        font6.setKerning(false);
        text_TC->setFont(font6);
        text_TC->setAcceptDrops(false);
        text_TC->setInputMethodHints(Qt::ImhNone);
        text_TC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_TC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_TC->setUndoRedoEnabled(false);
        text_TC->setReadOnly(true);
        text_TC->setAcceptRichText(false);
        text_POWER = new QTextEdit(Dialog);
        text_POWER->setObjectName(QString::fromUtf8("text_POWER"));
        text_POWER->setGeometry(QRect(950, 150, 141, 51));
        text_POWER->setFont(font6);
        text_POWER->setAcceptDrops(false);
        text_POWER->setInputMethodHints(Qt::ImhNone);
        text_POWER->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_POWER->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_POWER->setUndoRedoEnabled(false);
        text_POWER->setReadOnly(true);
        text_POWER->setAcceptRichText(false);
        text_RT = new QLineEdit(Dialog);
        text_RT->setObjectName(QString::fromUtf8("text_RT"));
        text_RT->setGeometry(QRect(950, 30, 141, 51));
        text_RT->setFont(font6);
        text_RT->setAcceptDrops(false);
        text_RT->setInputMethodHints(Qt::ImhNone);
        groupBox->raise();
        TC_Chart->raise();
        RTGraphRadioButton->raise();
        TCGraphRadioButton->raise();
        lcd_text_RT->raise();
        lineEdit->raise();
        lcd_text_TC->raise();
        lineEdit_2->raise();
        lcd_text_POWER->raise();
        lineEdit_3->raise();
        TemperatureControlModeRadioButton->raise();
        PowerControlModeRadioButton->raise();
        TargetTemperatureText->raise();
        SoftStop->raise();
        PowerOutputText->raise();
        TemperatureBandText->raise();
        KPText->raise();
        KIText->raise();
        TargetTemperatureSpin->raise();
        TemperatureBandSpin->raise();
        KPSpin->raise();
        KISpin->raise();
        PowerOutputSpin->raise();
        RT_Chart->raise();
        text_TC->raise();
        text_POWER->raise();
        text_RT->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Temperature", nullptr));
        RTGraphRadioButton->setText(QCoreApplication::translate("Dialog", "RT", nullptr));
        TCGraphRadioButton->setText(QCoreApplication::translate("Dialog", "TC", nullptr));
        lineEdit->setText(QCoreApplication::translate("Dialog", "RT", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Dialog", "TC", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Dialog", "Power", nullptr));
        TemperatureControlModeRadioButton->setText(QCoreApplication::translate("Dialog", "Temperature Control Mode", nullptr));
        PowerControlModeRadioButton->setText(QCoreApplication::translate("Dialog", "Power Control Mode", nullptr));
        TargetTemperatureText->setText(QCoreApplication::translate("Dialog", "Target Temperature", nullptr));
        SoftStop->setText(QCoreApplication::translate("Dialog", "Soft Stop", nullptr));
        PowerOutputText->setText(QCoreApplication::translate("Dialog", "Power Output", nullptr));
        TemperatureBandText->setText(QCoreApplication::translate("Dialog", "Temperature Band", nullptr));
        KPText->setText(QCoreApplication::translate("Dialog", "KP", nullptr));
        KIText->setText(QCoreApplication::translate("Dialog", "KI", nullptr));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
