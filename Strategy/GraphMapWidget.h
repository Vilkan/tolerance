#ifndef GRAPHMAPWIDGET_H
#define GRAPHMAPWIDGET_H

#include <QtWidgets>
#include <QtGui>

class GraphMapWidget : public QWidget
{
    Q_OBJECT

    public:
        GraphMapWidget(QWidget *parent = 0);
        void paintEvent(QPaintEvent*);

    private:
        QPalette pal1;
        QBoxLayout* pbxLayout;
};

#endif // GRAPHMAPWIDGET_H
