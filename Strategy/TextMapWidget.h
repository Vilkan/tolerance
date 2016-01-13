#ifndef TEXTMAPWIDGET_H
#define TEXTMAPWIDGET_H

#include <QtWidgets>
#include <QtGui>
#include "SectorWidget.h"

class TextMapWidget : public QWidget
{
    Q_OBJECT

    public:
        TextMapWidget(QWidget *parent = 0);

    private:
        QPalette pal1;
        QBoxLayout* pbxLayout;
        QFile fSector;
        SectorWidget* sectorWidget;
};

#endif // TEXTMAPWIDGET_H
