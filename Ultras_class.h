#ifndef ULTRAS_CLASS_H
#define ULTRAS_CLASS_H
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <QVector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Fan {
    char Name[30];
    char Club[30];
    char Documents[15];
    int Count;
    Fan() {
        qstrncpy(Name, "", sizeof(Name));
        qstrncpy(Club, "", sizeof(Club));
        qstrncpy(Documents, "", sizeof(Documents));
        Count = 0;
    }


    Fan(const char* name, const char* club, const char* documents, int count) {
        qstrncpy(Name, name, sizeof(Name));
        qstrncpy(Club, club, sizeof(Club));
        qstrncpy(Documents, documents, sizeof(Documents));
        Count = count;
    }

    friend QTextStream& operator>>(QTextStream& in, Fan& item) {
        QString name;
        name = in.readLine();
        qstrncpy(item.Name, name.toLatin1().data(), sizeof(item.Name));
        QString mydate;
        mydate = in.readLine();
        qstrncpy(item.Club, mydate.toLatin1().data(), sizeof(item.Club));
        QString section;
        section = in.readLine();
        qstrncpy(item.Documents, section.toLatin1().data(), sizeof(item.Documents));
        in >> item.Count;
        in.readLine();
        return in;
    }

    friend QTextStream& operator<<(QTextStream& out, const Fan& item) {
        out << item.Name  <<"\n"<< item.Club<<"\n"<< item.Documents <<"\n"<< item.Count << "\n";
        return out;
    }

    bool operator==(const Fan& other) const {
        return qstrcmp(Name, other.Name) == 0;
    }
};

class Ultras {
private:
    QVector <Fan> items;
public:
    Ultras() {}
    ~Ultras() {}
    Fan &operator[](int index) {
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
        Fan item;
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

    void Add(const Fan& newFan)
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
    Fan FindByDocuments(const char* documents) const {
        for (const auto& item : items) {
            if (qstrcmp(item.Documents, documents) == 0) {
                return item;
            }
        }
        return Fan();
    }
    static bool CompareByName(const Fan& a, const Fan& b) {
        return qstrcmp(a.Name, b.Name) < 0;
    }

    // Sort the fans by name
    void SortByName() {
        sort(items.begin(), items.end(), CompareByName);
    }

};
#endif // ULTRAS_CLASS_H
