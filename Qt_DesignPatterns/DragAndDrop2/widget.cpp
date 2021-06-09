#include "widget.h"
#include "ui_widget.h"
#include <QSplitter>
#include <QVBoxLayout>
#include "container.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSplitter * splitter = new QSplitter(this);

    splitter->addWidget(new Container(this));

    splitter->addWidget(new Container(this));
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(splitter);


}

Widget::~Widget()
{
    delete ui;
}

