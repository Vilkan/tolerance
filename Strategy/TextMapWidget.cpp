#include "TextMapWidget.h"

TextMapWidget::TextMapWidget(QWidget *parent) : QWidget(parent)
{
    pal1.setColor(this->backgroundRole(), Qt::green);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("mw");

    pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    this->setLayout(pbxLayout);

    fSector.setFileName("sector.txt");
    if (fSector.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSector);
        QString str;
        while (!stream.atEnd())
        {
            str = stream.readLine();
            sectorWidget = new SectorWidget(this);
            sectorWidget->setSectorInfo(str);
            pbxLayout->addWidget(sectorWidget, 1);
            qDebug()<<"TextMapWidget::TextMapWidget: str="<<str;
        }
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fSector.close();
    }
}



