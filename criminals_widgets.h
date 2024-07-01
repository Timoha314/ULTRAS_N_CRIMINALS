#ifndef CRIMINALS_WIDGETS_H
#define CRIMINALS_WIDGETS_H

#include <QWidget>

namespace Ui {
class Criminals_widgets;
}

class Criminals_widgets : public QWidget
{
    Q_OBJECT

public:
    explicit Criminals_widgets(QWidget *parent = nullptr);
    ~Criminals_widgets();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_lineEdit_4_editingFinished();

    void on_Put_in_Jail_clicked();


    void on_comboBox_activated(int index);

private:
    Ui::Criminals_widgets *ui;
};

#endif // CRIMINALS_WIDGETS_H
