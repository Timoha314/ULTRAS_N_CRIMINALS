/********************************************************************************
** Form generated from reading UI file 'criminals_widgets.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIMINALS_WIDGETS_H
#define UI_CRIMINALS_WIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Criminals_widgets
{
public:
    QTableView *base_of_criminals;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *Put_in_Jail;

    void setupUi(QWidget *Criminals_widgets)
    {
        if (Criminals_widgets->objectName().isEmpty())
            Criminals_widgets->setObjectName("Criminals_widgets");
        Criminals_widgets->resize(531, 574);
        base_of_criminals = new QTableView(Criminals_widgets);
        base_of_criminals->setObjectName("base_of_criminals");
        base_of_criminals->setGeometry(QRect(10, 10, 511, 291));
        lineEdit = new QLineEdit(Criminals_widgets);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 340, 231, 41));
        label = new QLabel(Criminals_widgets);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 300, 231, 41));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        pushButton = new QPushButton(Criminals_widgets);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 390, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        lineEdit_2 = new QLineEdit(Criminals_widgets);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(290, 340, 231, 41));
        label_2 = new QLabel(Criminals_widgets);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 300, 231, 41));
        label_2->setFont(font);
        pushButton_2 = new QPushButton(Criminals_widgets);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 390, 231, 41));
        pushButton_2->setFont(font1);
        label_3 = new QLabel(Criminals_widgets);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 470, 261, 41));
        label_3->setFont(font);
        lineEdit_4 = new QLineEdit(Criminals_widgets);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(290, 470, 231, 41));
        label_4 = new QLabel(Criminals_widgets);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 430, 231, 41));
        label_4->setFont(font);
        comboBox = new QComboBox(Criminals_widgets);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 470, 231, 91));
        comboBox->setFont(font1);
        label_5 = new QLabel(Criminals_widgets);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 430, 231, 41));
        label_5->setFont(font);
        Put_in_Jail = new QPushButton(Criminals_widgets);
        Put_in_Jail->setObjectName("Put_in_Jail");
        Put_in_Jail->setGeometry(QRect(290, 520, 231, 41));
        Put_in_Jail->setFont(font1);

        retranslateUi(Criminals_widgets);

        QMetaObject::connectSlotsByName(Criminals_widgets);
    } // setupUi

    void retranslateUi(QWidget *Criminals_widgets)
    {
        Criminals_widgets->setWindowTitle(QCoreApplication::translate("Criminals_widgets", "Form", nullptr));
        label->setText(QCoreApplication::translate("Criminals_widgets", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217:", nullptr));
        pushButton->setText(QCoreApplication::translate("Criminals_widgets", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("Criminals_widgets", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Criminals_widgets", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_3->setText(QCoreApplication::translate("Criminals_widgets", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        lineEdit_4->setText(QString());
        label_4->setText(QCoreApplication::translate("Criminals_widgets", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Criminals_widgets", "\320\230\320\274\320\265\320\275\320\270", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Criminals_widgets", "\320\224\320\260\321\202\320\265 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Criminals_widgets", "\320\232\320\276\320\273-\320\262\321\203 \320\267\320\260\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\271", nullptr));

        label_5->setText(QCoreApplication::translate("Criminals_widgets", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276:", nullptr));
        Put_in_Jail->setText(QCoreApplication::translate("Criminals_widgets", "\320\237\320\276\321\201\320\260\320\264\320\270\321\202\321\214 \320\275\320\260 15 \321\201\321\203\321\202\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Criminals_widgets: public Ui_Criminals_widgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIMINALS_WIDGETS_H
