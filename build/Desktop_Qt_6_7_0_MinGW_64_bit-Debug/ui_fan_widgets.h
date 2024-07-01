/********************************************************************************
** Form generated from reading UI file 'fan_widgets.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAN_WIDGETS_H
#define UI_FAN_WIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fan_widgets
{
public:
    QTableView *base_of_ultras;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Fan_widgets)
    {
        if (Fan_widgets->objectName().isEmpty())
            Fan_widgets->setObjectName("Fan_widgets");
        Fan_widgets->resize(572, 580);
        base_of_ultras = new QTableView(Fan_widgets);
        base_of_ultras->setObjectName("base_of_ultras");
        base_of_ultras->setGeometry(QRect(10, 10, 551, 321));
        pushButton = new QPushButton(Fan_widgets);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 420, 261, 41));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        lineEdit = new QLineEdit(Fan_widgets);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 370, 261, 41));
        pushButton_2 = new QPushButton(Fan_widgets);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 420, 261, 41));
        pushButton_2->setFont(font);
        lineEdit_2 = new QLineEdit(Fan_widgets);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 370, 261, 41));
        label = new QLabel(Fan_widgets);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 330, 261, 41));
        QFont font1;
        font1.setPointSize(9);
        label->setFont(font1);
        label_2 = new QLabel(Fan_widgets);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 330, 261, 41));
        label_2->setFont(font1);
        lineEdit_3 = new QLineEdit(Fan_widgets);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(300, 500, 261, 41));
        label_3 = new QLabel(Fan_widgets);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 460, 261, 41));
        label_3->setFont(font1);
        pushButton_3 = new QPushButton(Fan_widgets);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 500, 261, 41));
        pushButton_3->setFont(font);

        retranslateUi(Fan_widgets);

        QMetaObject::connectSlotsByName(Fan_widgets);
    } // setupUi

    void retranslateUi(QWidget *Fan_widgets)
    {
        Fan_widgets->setWindowTitle(QCoreApplication::translate("Fan_widgets", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Fan_widgets", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Fan_widgets", "\320\230\321\201\320\272\320\260\321\202\321\214 ", nullptr));
        label->setText(QCoreApplication::translate("Fan_widgets", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("Fan_widgets", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
        lineEdit_3->setText(QString());
        label_3->setText(QCoreApplication::translate("Fan_widgets", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Fan_widgets", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fan_widgets: public Ui_Fan_widgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAN_WIDGETS_H
