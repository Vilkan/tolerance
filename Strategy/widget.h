#ifndef WIDGET_H
#define WIDGET_H

#include "ButtonWidget.h"
#include "MapWidget.h"
#include "StatisticWidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    ButtonWidget* bw;
    MapWidget* mw;
    StatisticWidget* sw;
    QGridLayout* layout;

};

#endif // WIDGET_H
