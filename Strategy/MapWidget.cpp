#include "MapWidget.h"

MapWidget::MapWidget(QWidget *parent)
    : QWidget(parent)
{
    pal1.setColor(this->backgroundRole(), Qt::gray);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("mw");

    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    tmw = new TextMapWidget(this);
    pbxLayout->addWidget(tmw, 1);
    gmw = new GraphMapWidget(this);
    pbxLayout->addWidget(gmw, 1);
    //gmw->hide();





    this->setLayout(pbxLayout);

}


