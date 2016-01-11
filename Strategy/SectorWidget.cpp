#include "SectorWidget.h"

SectorWidget::SectorWidget(QWidget *parent) : QWidget(parent)
{
    QPalette pal1;
    pal1.setColor(this->backgroundRole(), Qt::white);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("sectorWidget");
    pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(pbxLayout);
}

void SectorWidget::mousePressEvent(QMouseEvent *pe)
{
    sectorDialog = new SectorDialog(sectorInfo);
    sectorDialog->show();
}

void SectorWidget::setSectorInfo(QString str)
{
    lSector = new QLabel(str);
    pbxLayout->addWidget(lSector);
    sectorInfo=str;
    qDebug()<<"SectorWidget::setSectorInfo: sectorInfo="<<sectorInfo;
}

