#include "fan_widgets.h"
#include "ui_fan_widgets.h"
#include "Ultras_class.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QVector>
#include <QTableView>
#include <QAbstractTableModel>
#include <QTextStream>
#include <QFile>
#include <fstream>
#include <iostream>

Ultras ultras;
Fan_widgets::Fan_widgets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Fan_widgets)
{
    ui->setupUi(this);
    // Создаем модель данных
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setColumnCount(4); // Четыре столбца
    // Названия столбцов
    model->setHorizontalHeaderLabels(QStringList() << "Имя" << "Клуб" << "Паспорт" << "Кол-во пива в л.");
    // Добавляем модель к таблице
    ui->base_of_ultras->setModel(model);


    // Загружаем данные из файла (предполагается, что файл называется "ultras_data.txt")
    ultras.ReadData("ultras.txt");

    // Получаем модель данных из вашей таблицы

    // Заполняем модель данными из вектора Ultras
    for (int i=0;i<ultras.GetCount();i++) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(ultras[i].Name)
                 << new QStandardItem(ultras[i].Club)
                 << new QStandardItem(ultras[i].Documents)
                 << new QStandardItem(QString::number(ultras[i].Count));
        model->appendRow(rowItems);
    }

}
Fan_widgets::~Fan_widgets()
{
    delete ui;
}


// Assuming you have a QLineEdit named "lineEdit" and a QPushButton named "pushButton" in your UI
// Assuming you have a QLineEdit named "lineEdit" and a QPushButton named "pushButton" in your UI

Fan newFan; // Declare a new Fan object

void Fan_widgets::on_lineEdit_textEdited(const QString &arg1)
{
    QStringList parts = arg1.split('|'); // Разделяем строку по пробелам

    if (parts.size() >= 4) {
        // Создаем массивы char для каждого параметра
        char name[100]; // Пример размера массива
        char club[100];
        char documents[100];
        int count = parts[3].toInt(); // Преобразуем строку в целое число

        // Копируем значения из QStringList в массивы char
        qstrncpy(name, parts[0].toLatin1().data(), sizeof(name));
        qstrncpy(club, parts[1].toLatin1().data(), sizeof(club));
        qstrncpy(documents, parts[2].toLatin1().data(), sizeof(documents));

        // Создаем объект Fan с использованием массивов char
        newFan = Fan(name, club, documents, count);
    } else {
        cout << "error"; // Обработка случая, когда не хватает параметров
    }

}


void Fan_widgets::on_pushButton_clicked()
{
    ultras.Add(newFan); // Assuming you have an Add() function in Ultras
    ultras.WriteData("ultras.txt"); // Save data to file

    // Update the model to reflect the changes
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->base_of_ultras->model());
    if (model) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(newFan.Name)
                 << new QStandardItem(newFan.Club)
                 << new QStandardItem(newFan.Documents)
                 << new QStandardItem(QString::number(newFan.Count));
        model->appendRow(rowItems);
    }
    ui->lineEdit->clear();
}


Fan result;
void Fan_widgets::on_lineEdit_2_textEdited(const QString &arg1)
{
    //QString Passport = ui->lineEdit_2->text();
    QByteArray ba = arg1.toLocal8Bit();
    const char* charArray = ba.constData();
    result = ultras.FindByDocuments(charArray);
}

void Fan_widgets::on_pushButton_2_clicked()
{

        QString passport = ui->lineEdit_2->text();
        QByteArray ba = passport.toLocal8Bit();
        const char* charArray = ba.constData();


        QString currentText = ui->lineEdit_3->text();
        currentText.append(result.Name);
        currentText.append(" ");
        currentText.append(result.Club);
        currentText.append(" ");
        currentText.append(QString::number(result.Count));
        ui->lineEdit_3->setText(currentText);
        ui->lineEdit_2->clear();
}


void Fan_widgets::on_lineEdit_3_editingFinished()
{

}


void Fan_widgets::on_pushButton_3_clicked()
{
    ultras.SortByName();
    QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->base_of_ultras->model());
    model->removeRows(0, model->rowCount());
    for (int i = 0; i < ultras.GetCount(); ++i) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(ultras[i].Name)
                 << new QStandardItem(ultras[i].Club)
                 << new QStandardItem(ultras[i].Documents)
                 << new QStandardItem(QString::number(ultras[i].Count));
        model->appendRow(rowItems);
    }
}

