#ifndef SECTORWIDGET_H
#define SECTORWIDGET_H

#include <QtWidgets>
#include <QtGui>
#include "SectorDialog.h"

class SectorWidget : public QWidget
{
    Q_OBJECT
public:
    SectorWidget(QWidget *parent = 0);
    void setSectorInfo(QString);

protected:
    virtual void mousePressEvent(QMouseEvent* pe);

private:
    QBoxLayout* pbxLayout;
    QLabel* lSector;
    SectorDialog* sectorDialog;
    QString sectorInfo;
};

#endif // SECTORWIDGET_H
