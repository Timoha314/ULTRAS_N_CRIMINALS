#ifndef FAN_WIDGETS_H
#define FAN_WIDGETS_H

#include <QWidget>

namespace Ui {
class Fan_widgets;
}

class Fan_widgets : public QWidget
{
    Q_OBJECT

public:
    explicit Fan_widgets(QWidget *parent = nullptr);
    ~Fan_widgets();

private slots:





    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_lineEdit_3_editingFinished();

    void on_pushButton_3_clicked();

private:
    Ui::Fan_widgets *ui;
};

#endif // FAN_WIDGETS_H
