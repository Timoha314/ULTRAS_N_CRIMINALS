#include "criminals_widgets.h"
#include "ui_criminals_widgets.h"
#include "Criminal_class.h"
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


Criminals criminals;
Criminals_widgets::Criminals_widgets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Criminals_widgets)
{

    ui->setupUi(this);
    // Создаем модель данных
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setColumnCount(4); // Четыре столбца
    // Названия столбцов
    model->setHorizontalHeaderLabels(QStringList() << "Имя" << "Дата рождения" << "Паспорт" << "Кол-во задержаний");
    // Добавляем модель к таблице
    ui->base_of_criminals->setModel(model);


    // Загружаем данные из файла (предполагается, что файл называется "ultras_data.txt")
    criminals.ReadData("criminals.txt");

    // Получаем модель данных из вашей таблицы

    // Заполняем модель данными из вектора Ultras
    for (int i=0;i<criminals.GetCount();i++) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(criminals[i].Name)
                 << new QStandardItem(criminals[i].Date)
                 << new QStandardItem(criminals[i].Documents)
                 << new QStandardItem(QString::number(criminals[i].Count));
        model->appendRow(rowItems);
    }
     ui->Put_in_Jail->setVisible(false);
}

Criminals_widgets::~Criminals_widgets()
{
    delete ui;
}
Criminal newCriminal;
void Criminals_widgets::on_lineEdit_textEdited(const QString &arg1)
{
    QStringList parts = arg1.split('|'); // Разделяем строку по пробелам

    if (parts.size() >= 4) {
        // Создаем массивы char для каждого параметра
        char name[100]; // Пример размера массива
        char date[100];
        char documents[100];
        int count = parts[3].toInt(); // Преобразуем строку в целое число

        // Копируем значения из QStringList в массивы char
        qstrncpy(name, parts[0].toLatin1().data(), sizeof(name));
        qstrncpy(date, parts[1].toLatin1().data(), sizeof(date));
        qstrncpy(documents, parts[2].toLatin1().data(), sizeof(documents));

        // Создаем объект Fan с использованием массивов char
        newCriminal = Criminal(name, date, documents, count);
    } else {
        cout << "error"; // Обработка случая, когда не хватает параметров
    }
}


void Criminals_widgets::on_pushButton_clicked()
{
    criminals.Add(newCriminal); // Assuming you have an Add() function in Ultras
    criminals.WriteData("criminals.txt"); // Save data to file

    // Update the model to reflect the changes
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(ui->base_of_criminals->model());
    if (model) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(newCriminal.Name)
                 << new QStandardItem(newCriminal.Date)
                 << new QStandardItem(newCriminal.Documents)
                 << new QStandardItem(QString::number(newCriminal.Count));
        model->appendRow(rowItems);
    }
    ui->lineEdit->clear();
}

Criminal result1;
void Criminals_widgets::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->lineEdit_4->clear();
    QByteArray ba = arg1.toLocal8Bit();
    const char* charArray = ba.constData();
    result1 = criminals.FindByDocuments(charArray);
}


void Criminals_widgets::on_pushButton_2_clicked()
{
    QString passport = ui->lineEdit_2->text();

    QByteArray ba = passport.toLocal8Bit();
    const char* charArray = ba.constData();

    QString currentText = ui->lineEdit_4->text();
    currentText.append(result1.Name);
    currentText.append(" ");
    currentText.append(result1.Date);
    currentText.append(" ");
    currentText.append(QString::number(result1.Count));
    ui->lineEdit_4->setText(currentText);
    ui->lineEdit_2->clear();
    ui->Put_in_Jail->setVisible(true);
}


void Criminals_widgets::on_lineEdit_4_editingFinished()
{

}




void Criminals_widgets::on_Put_in_Jail_clicked()
{
    int index = criminals.returnIndex(result1);
    criminals[index].PutInJail();
    criminals.WriteData("criminals.txt");
    QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->base_of_criminals->model());
    model->removeRows(0, model->rowCount());
    for (int i = 0; i < criminals.GetCount(); ++i) {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(criminals[i].Name)
                 << new QStandardItem(criminals[i].Date)
                 << new QStandardItem(criminals[i].Documents)
                 << new QStandardItem(QString::number(criminals[i].Count));
        model->appendRow(rowItems);
    }
}



void Criminals_widgets::on_comboBox_activated(int index)
{
    if(index==0){
        criminals.SortByName();
        QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->base_of_criminals->model());
        model->removeRows(0, model->rowCount());
        for (int i = 0; i < criminals.GetCount(); ++i) {
            QList<QStandardItem*> rowItems;
            rowItems << new QStandardItem(criminals[i].Name)
                     << new QStandardItem(criminals[i].Date)
                     << new QStandardItem(criminals[i].Documents)
                     << new QStandardItem(QString::number(criminals[i].Count));
            model->appendRow(rowItems);
        }
    }
    else if(index==1){

        criminals.SortByBirthDate();
        QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->base_of_criminals->model());
        model->removeRows(0, model->rowCount());
        for (int i = 0; i < criminals.GetCount(); ++i) {
            QList<QStandardItem*> rowItems;
            rowItems << new QStandardItem(criminals[i].Name)
                     << new QStandardItem(criminals[i].Date)
                     << new QStandardItem(criminals[i].Documents)
                     << new QStandardItem(QString::number(criminals[i].Count));
                model->appendRow(rowItems);
        }

    }

    else if(index==2){
        criminals.SortByCount();
        QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->base_of_criminals->model());
        model->removeRows(0, model->rowCount());
        for (int i = 0; i < criminals.GetCount(); ++i) {
            QList<QStandardItem*> rowItems;
            rowItems << new QStandardItem(criminals[i].Name)
                     << new QStandardItem(criminals[i].Date)
                     << new QStandardItem(criminals[i].Documents)
                     << new QStandardItem(QString::number(criminals[i].Count));
            model->appendRow(rowItems);
    }
    }
}

