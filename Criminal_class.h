#ifndef CRIMINAL_CLASS_H
#define CRIMINAL_CLASS_H
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <QVector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Criminal {
    char Name[30];
    char Date[30];
    char Documents[15];
    int Count;
    Criminal() {
        qstrncpy(Name, "", sizeof(Name));
        qstrncpy(Date, "", sizeof(Date));
        qstrncpy(Documents, "", sizeof(Documents));
        Count = 0;
    }


    Criminal(const char* name, const char* date, const char* documents, int count) {
        qstrncpy(Name, name, sizeof(Name));
        qstrncpy(Date, date, sizeof(Date));
        qstrncpy(Documents, documents, sizeof(Documents));
        Count = count;
    }

    friend QTextStream& operator>>(QTextStream& in, Criminal& item) {
        QString name;
        name = in.readLine();
        qstrncpy(item.Name, name.toLatin1().data(), sizeof(item.Name));
        QString mydate;
        mydate = in.readLine();
        qstrncpy(item.Date, mydate.toLatin1().data(), sizeof(item.Date));
        QString section;
        section = in.readLine();
        qstrncpy(item.Documents, section.toLatin1().data(), sizeof(item.Documents));
        in >> item.Count;
        in.readLine();
        return in;
    }

    friend QTextStream& operator<<(QTextStream& out, const Criminal& item) {
        out << item.Name  <<"\n"<< item.Date<<"\n"<< item.Documents <<"\n"<< item.Count << "\n";
        return out;
    }

    bool operator==(const Criminal& other) const {
        return qstrcmp(Name, other.Name) == 0;
    }
    void PutInJail(){
        Count++;
    }
};

class Criminals {
private:
    QVector <Criminal> items;
public:
    Criminals() {}
    ~Criminals() {}
    Criminal &operator[](int index) {
        if (index >= 0 && index < items.size()) {
            return items[index];
        } else {
            throw out_of_range("Индекс вне диапазона");
        }
    }
    void ReadData(const QString& filename) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning("Cannot open file for reading");
            return;
        }

        QTextStream in(&file);
        Criminal item;
        while (!in.atEnd()) {
            in >> item;
            items.append(item);
        }

        file.close();
    }

    void WriteData(const QString& filename) const {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning("Cannot open file for writing");
            return;
        }

        QTextStream out(&file);
        for (const auto& item : items) {
            out << item;
        }

        file.close();
    }

    void Add(const Criminal& newFan)
    {
        items.append(newFan);
    }

    void print() const {
        QTextStream out(stdout);
        out << "\n";
        for (const auto& item : items) {
            out << item;
        }
    }
    int GetCount() const {
        return items.count();
    }
    Criminal FindByDocuments(const char* documents) const {
        for (const auto& item : items) {
            if (qstrcmp(item.Documents, documents) == 0) {
                return item;
            }
        }
        return Criminal();
    }
    static bool CompareByCount(const Criminal& a, const Criminal& b) {
        return a.Count>b.Count;
    }
    static bool CompareByName(const Criminal& a, const Criminal& b) {
        return qstrcmp(a.Name, b.Name) < 0;
    }
    struct CompareByBirthDate {
        bool operator()(const Criminal& a, const Criminal& b) const {
            // Получаем даты рождения из параметров a и b
            QString dateA = QString::fromUtf8(a.Date);
            QString dateB = QString::fromUtf8(b.Date);

            // Извлекаем день, месяц и год из строк даты
            int dayA = dateA.mid(0, 2).toInt();
            int monthA = dateA.mid(3, 2).toInt();
            int yearA = dateA.mid(6, 4).toInt();

            int dayB = dateB.mid(0, 2).toInt();
            int monthB = dateB.mid(3, 2).toInt();
            int yearB = dateB.mid(6, 4).toInt();

            // Сравниваем годы
            if (yearA != yearB) {
                return yearA < yearB;
            }
            // Если годы одинаковые, сравниваем месяцы
            else if (monthA != monthB) {
                return monthA < monthB;
            }
            // Если месяцы одинаковые, сравниваем дни
            else {
                return dayA < dayB;
            }
        }
    };


    // Sort the fans by name
    void SortByName() {
        sort(items.begin(), items.end(), CompareByName);
    }
    void SortByCount() {
        sort(items.begin(), items.end(), CompareByCount);
    }
    void SortByBirthDate() {
        sort(items.begin(), items.end(), CompareByBirthDate());
    }

    int returnIndex(Criminal item){
        for(int i=0;i<items.size();i++){
            if(items[i]==item)return i;
        }
        return -1;
    }

};
#endif // CRIMINAL_CLASS_H
