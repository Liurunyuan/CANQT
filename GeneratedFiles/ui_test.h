/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_acc;
    QLineEdit *lineEdit_acc;
    QLabel *label_mask;
    QLineEdit *lineEdit_mask;
    QLabel *label_filter;
    QComboBox *comboBox_filter;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_btr0;
    QLineEdit *lineEdit_btr0;
    QLabel *label_btr1;
    QLineEdit *lineEdit_btr1;
    QLabel *label_mode;
    QComboBox *comboBox_mode;
    QPushButton *BtnConnect;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_dev;
    QComboBox *comboBox_dev;
    QLabel *label_index;
    QComboBox *comboBox_index;
    QLabel *label_can;
    QComboBox *comboBox_can;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_send;
    QComboBox *comboBox_send;
    QLabel *label_type;
    QComboBox *m_ComboSendFrmType;
    QLabel *label_format;
    QComboBox *comboBox_format;
    QLabel *label_ID;
    QLineEdit *m_EditSendFrmID;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_data;
    QLineEdit *m_EditSendData;
    QPushButton *BtnSend;
    QGroupBox *groupBox_4;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BtnStart;
    QPushButton *BtnReset;
    QCustomPlot *curve;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(1300, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(703, 458));
        Dialog->setMaximumSize(QSize(2222, 2222));
        Dialog->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(10);
        Dialog->setFont(font);
        Dialog->setMouseTracking(false);
        Dialog->setLayoutDirection(Qt::LeftToRight);
        Dialog->setAutoFillBackground(false);
        Dialog->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(false);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 581, 171));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 60, 541, 91));
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 0, 501, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_acc = new QLabel(horizontalLayoutWidget_2);
        label_acc->setObjectName(QString::fromUtf8("label_acc"));

        horizontalLayout_2->addWidget(label_acc);

        lineEdit_acc = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_acc->setObjectName(QString::fromUtf8("lineEdit_acc"));

        horizontalLayout_2->addWidget(lineEdit_acc);

        label_mask = new QLabel(horizontalLayoutWidget_2);
        label_mask->setObjectName(QString::fromUtf8("label_mask"));

        horizontalLayout_2->addWidget(label_mask);

        lineEdit_mask = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_mask->setObjectName(QString::fromUtf8("lineEdit_mask"));

        horizontalLayout_2->addWidget(lineEdit_mask);

        label_filter = new QLabel(horizontalLayoutWidget_2);
        label_filter->setObjectName(QString::fromUtf8("label_filter"));

        horizontalLayout_2->addWidget(label_filter);

        comboBox_filter = new QComboBox(horizontalLayoutWidget_2);
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->setObjectName(QString::fromUtf8("comboBox_filter"));

        horizontalLayout_2->addWidget(comboBox_filter);

        horizontalLayoutWidget_3 = new QWidget(groupBox_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 50, 491, 49));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_btr0 = new QLabel(horizontalLayoutWidget_3);
        label_btr0->setObjectName(QString::fromUtf8("label_btr0"));

        horizontalLayout_3->addWidget(label_btr0);

        lineEdit_btr0 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_btr0->setObjectName(QString::fromUtf8("lineEdit_btr0"));

        horizontalLayout_3->addWidget(lineEdit_btr0);

        label_btr1 = new QLabel(horizontalLayoutWidget_3);
        label_btr1->setObjectName(QString::fromUtf8("label_btr1"));

        horizontalLayout_3->addWidget(label_btr1);

        lineEdit_btr1 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_btr1->setObjectName(QString::fromUtf8("lineEdit_btr1"));

        horizontalLayout_3->addWidget(lineEdit_btr1);

        label_mode = new QLabel(horizontalLayoutWidget_3);
        label_mode->setObjectName(QString::fromUtf8("label_mode"));

        horizontalLayout_3->addWidget(label_mode);

        comboBox_mode = new QComboBox(horizontalLayoutWidget_3);
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->setObjectName(QString::fromUtf8("comboBox_mode"));

        horizontalLayout_3->addWidget(comboBox_mode);

        BtnConnect = new QPushButton(groupBox);
        BtnConnect->setObjectName(QString::fromUtf8("BtnConnect"));
        BtnConnect->setGeometry(QRect(500, 20, 75, 23));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 461, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_dev = new QLabel(horizontalLayoutWidget);
        label_dev->setObjectName(QString::fromUtf8("label_dev"));
        label_dev->setMinimumSize(QSize(54, 0));
        label_dev->setMaximumSize(QSize(54, 12));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label_dev->setFont(font1);

        horizontalLayout->addWidget(label_dev);

        comboBox_dev = new QComboBox(horizontalLayoutWidget);
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->addItem(QString());
        comboBox_dev->setObjectName(QString::fromUtf8("comboBox_dev"));

        horizontalLayout->addWidget(comboBox_dev);

        label_index = new QLabel(horizontalLayoutWidget);
        label_index->setObjectName(QString::fromUtf8("label_index"));

        horizontalLayout->addWidget(label_index);

        comboBox_index = new QComboBox(horizontalLayoutWidget);
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->addItem(QString());
        comboBox_index->setObjectName(QString::fromUtf8("comboBox_index"));

        horizontalLayout->addWidget(comboBox_index);

        label_can = new QLabel(horizontalLayoutWidget);
        label_can->setObjectName(QString::fromUtf8("label_can"));

        horizontalLayout->addWidget(label_can);

        comboBox_can = new QComboBox(horizontalLayoutWidget);
        comboBox_can->addItem(QString());
        comboBox_can->addItem(QString());
        comboBox_can->setObjectName(QString::fromUtf8("comboBox_can"));

        horizontalLayout->addWidget(comboBox_can);

        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(590, 80, 691, 101));
        horizontalLayoutWidget_4 = new QWidget(groupBox_3);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 673, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_send = new QLabel(horizontalLayoutWidget_4);
        label_send->setObjectName(QString::fromUtf8("label_send"));

        horizontalLayout_6->addWidget(label_send);

        comboBox_send = new QComboBox(horizontalLayoutWidget_4);
        comboBox_send->addItem(QString());
        comboBox_send->addItem(QString());
        comboBox_send->addItem(QString());
        comboBox_send->addItem(QString());
        comboBox_send->setObjectName(QString::fromUtf8("comboBox_send"));

        horizontalLayout_6->addWidget(comboBox_send);

        label_type = new QLabel(horizontalLayoutWidget_4);
        label_type->setObjectName(QString::fromUtf8("label_type"));
        label_type->setEnabled(true);

        horizontalLayout_6->addWidget(label_type);

        m_ComboSendFrmType = new QComboBox(horizontalLayoutWidget_4);
        m_ComboSendFrmType->addItem(QString());
        m_ComboSendFrmType->addItem(QString());
        m_ComboSendFrmType->setObjectName(QString::fromUtf8("m_ComboSendFrmType"));

        horizontalLayout_6->addWidget(m_ComboSendFrmType);

        label_format = new QLabel(horizontalLayoutWidget_4);
        label_format->setObjectName(QString::fromUtf8("label_format"));

        horizontalLayout_6->addWidget(label_format);

        comboBox_format = new QComboBox(horizontalLayoutWidget_4);
        comboBox_format->addItem(QString());
        comboBox_format->addItem(QString());
        comboBox_format->setObjectName(QString::fromUtf8("comboBox_format"));

        horizontalLayout_6->addWidget(comboBox_format);

        label_ID = new QLabel(horizontalLayoutWidget_4);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));

        horizontalLayout_6->addWidget(label_ID);

        m_EditSendFrmID = new QLineEdit(horizontalLayoutWidget_4);
        m_EditSendFrmID->setObjectName(QString::fromUtf8("m_EditSendFrmID"));

        horizontalLayout_6->addWidget(m_EditSendFrmID);

        horizontalLayoutWidget_5 = new QWidget(groupBox_3);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 60, 431, 41));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_data = new QLabel(horizontalLayoutWidget_5);
        label_data->setObjectName(QString::fromUtf8("label_data"));

        horizontalLayout_8->addWidget(label_data);

        m_EditSendData = new QLineEdit(horizontalLayoutWidget_5);
        m_EditSendData->setObjectName(QString::fromUtf8("m_EditSendData"));

        horizontalLayout_8->addWidget(m_EditSendData);

        BtnSend = new QPushButton(horizontalLayoutWidget_5);
        BtnSend->setObjectName(QString::fromUtf8("BtnSend"));

        horizontalLayout_8->addWidget(BtnSend);

        groupBox_4 = new QGroupBox(Dialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 190, 1221, 171));
        tableWidget = new QTableWidget(groupBox_4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 1201, 141));
        tableWidget->setLineWidth(1);
        tableWidget->setMidLineWidth(0);
        tableWidget->horizontalHeader()->setMinimumSectionSize(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        tableWidget->verticalHeader()->setMinimumSectionSize(0);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(600, 30, 158, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        BtnStart = new QPushButton(layoutWidget);
        BtnStart->setObjectName(QString::fromUtf8("BtnStart"));

        horizontalLayout_4->addWidget(BtnStart);

        BtnReset = new QPushButton(layoutWidget);
        BtnReset->setObjectName(QString::fromUtf8("BtnReset"));

        horizontalLayout_4->addWidget(BtnReset);

        curve = new QCustomPlot(Dialog);
        curve->setObjectName(QString::fromUtf8("curve"));
        curve->setGeometry(QRect(29, 389, 1181, 341));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        Dialog->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QCoreApplication::translate("Dialog", "Device Parameter", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "Init CAN", nullptr));
        label_acc->setText(QCoreApplication::translate("Dialog", "Acc Code:0x", nullptr));
        lineEdit_acc->setText(QCoreApplication::translate("Dialog", "00000000", nullptr));
        label_mask->setText(QCoreApplication::translate("Dialog", "Mask Code:0x", nullptr));
        lineEdit_mask->setText(QCoreApplication::translate("Dialog", "ffffffff", nullptr));
        label_filter->setText(QCoreApplication::translate("Dialog", "Filter:", nullptr));
        comboBox_filter->setItemText(0, QCoreApplication::translate("Dialog", "Dual Filter", nullptr));
        comboBox_filter->setItemText(1, QCoreApplication::translate("Dialog", "Single Filter", nullptr));

        label_btr0->setText(QCoreApplication::translate("Dialog", "BTR0:0x", nullptr));
        lineEdit_btr0->setText(QCoreApplication::translate("Dialog", "00", nullptr));
        label_btr1->setText(QCoreApplication::translate("Dialog", "BTR1:0x", nullptr));
        lineEdit_btr1->setText(QCoreApplication::translate("Dialog", "14", nullptr));
        label_mode->setText(QCoreApplication::translate("Dialog", "Mode:", nullptr));
        comboBox_mode->setItemText(0, QCoreApplication::translate("Dialog", "Normal", nullptr));
        comboBox_mode->setItemText(1, QCoreApplication::translate("Dialog", "ReadOnly", nullptr));

        BtnConnect->setText(QCoreApplication::translate("Dialog", "Connect", nullptr));
        label_dev->setText(QCoreApplication::translate("Dialog", "Device:", nullptr));
        comboBox_dev->setItemText(0, QCoreApplication::translate("Dialog", "USBCAN-2I/2I+", nullptr));
        comboBox_dev->setItemText(1, QCoreApplication::translate("Dialog", "USBalyst-II", nullptr));
        comboBox_dev->setItemText(2, QCoreApplication::translate("Dialog", "PCICAN-9820", nullptr));
        comboBox_dev->setItemText(3, QCoreApplication::translate("Dialog", "PCICAN-9840", nullptr));
        comboBox_dev->setItemText(4, QCoreApplication::translate("Dialog", "iCANEC-I", nullptr));
        comboBox_dev->setItemText(5, QCoreApplication::translate("Dialog", "104plusCAN-II", nullptr));
        comboBox_dev->setItemText(6, QCoreApplication::translate("Dialog", "USBCAN-I", nullptr));
        comboBox_dev->setItemText(7, QCoreApplication::translate("Dialog", "PCIE9221", nullptr));

        label_index->setText(QCoreApplication::translate("Dialog", "Index:", nullptr));
        comboBox_index->setItemText(0, QCoreApplication::translate("Dialog", "0", nullptr));
        comboBox_index->setItemText(1, QCoreApplication::translate("Dialog", "1", nullptr));
        comboBox_index->setItemText(2, QCoreApplication::translate("Dialog", "2", nullptr));
        comboBox_index->setItemText(3, QCoreApplication::translate("Dialog", "3", nullptr));
        comboBox_index->setItemText(4, QCoreApplication::translate("Dialog", "4", nullptr));
        comboBox_index->setItemText(5, QCoreApplication::translate("Dialog", "5", nullptr));
        comboBox_index->setItemText(6, QCoreApplication::translate("Dialog", "6", nullptr));
        comboBox_index->setItemText(7, QCoreApplication::translate("Dialog", "7", nullptr));

        label_can->setText(QCoreApplication::translate("Dialog", "CAN:", nullptr));
        comboBox_can->setItemText(0, QCoreApplication::translate("Dialog", "0", nullptr));
        comboBox_can->setItemText(1, QCoreApplication::translate("Dialog", "1", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("Dialog", "Send Data Frame", nullptr));
        label_send->setText(QCoreApplication::translate("Dialog", "Send Format:", nullptr));
        comboBox_send->setItemText(0, QCoreApplication::translate("Dialog", "Normal Send", nullptr));
        comboBox_send->setItemText(1, QCoreApplication::translate("Dialog", "Single Send", nullptr));
        comboBox_send->setItemText(2, QCoreApplication::translate("Dialog", "Send & Recive", nullptr));
        comboBox_send->setItemText(3, QCoreApplication::translate("Dialog", "Single Send & Recive", nullptr));

        label_type->setText(QCoreApplication::translate("Dialog", "Type:", nullptr));
        m_ComboSendFrmType->setItemText(0, QCoreApplication::translate("Dialog", "Extern Frame", nullptr));
        m_ComboSendFrmType->setItemText(1, QCoreApplication::translate("Dialog", "Standard Frame", nullptr));

        label_format->setText(QCoreApplication::translate("Dialog", "Format:", nullptr));
        comboBox_format->setItemText(0, QCoreApplication::translate("Dialog", "Data Frame", nullptr));
        comboBox_format->setItemText(1, QCoreApplication::translate("Dialog", "Remote Frame", nullptr));

        label_ID->setText(QCoreApplication::translate("Dialog", "ID:", nullptr));
        m_EditSendFrmID->setText(QCoreApplication::translate("Dialog", "00000080", nullptr));
        label_data->setText(QCoreApplication::translate("Dialog", "Data:", nullptr));
        m_EditSendData->setText(QCoreApplication::translate("Dialog", "01 02 03 04 05 06 07 08", nullptr));
        BtnSend->setText(QCoreApplication::translate("Dialog", "Send", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Dialog", "information", nullptr));
        BtnStart->setText(QCoreApplication::translate("Dialog", "Start CAN", nullptr));
        BtnReset->setText(QCoreApplication::translate("Dialog", "Reset CAN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
