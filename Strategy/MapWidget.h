#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "TextMapWidget.h"
#include "GraphMapWidget.h"
#include <QtWidgets>
#include <QtGui>

class MapWidget : public QWidget
{
        Q_OBJECT

        public:
            MapWidget(QWidget *parent = 0);

        private:
            QPalette pal1;
            QBoxLayout* pbxLayout;
            QPalette pall;
            TextMapWidget* tmw;
            GraphMapWidget* gmw;


};

#endif // MAPWIDGET_H
