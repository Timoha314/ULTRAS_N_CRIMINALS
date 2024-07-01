#include "ultras_widgets.h"
#include "ui_ultras_widgets.h"

Criminals_widgets::Criminals_widgets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Criminals_widgets)
{
    ui->setupUi(this);
}

Criminals_widgets::~Criminals_widgets()
{
    delete ui;
}
