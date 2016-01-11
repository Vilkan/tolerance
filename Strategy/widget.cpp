#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout;
    this->setLayout(layout);
    this->setMinimumSize(700, 400);

    setWindowTitle(tr("Tolerant diary"));

    bw = new ButtonWidget(this);
    layout->addWidget(bw, 0, 0, 1, 1, 0);

    mw = new MapWidget(this);
    layout->addWidget(mw, 1, 0, 9, 1, 0);

    sw = new StatisticWidget(this);
    layout->addWidget(sw, 10, 0, 1, 1, 0);
}

Widget::~Widget()
{

}
