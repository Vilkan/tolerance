#ifndef SPACESECTORDIALOG_H
#define SPACESECTORDIALOG_H

//#include <QtWidgets>
#include <QtGui>
#include "SpaceShipWidget.h"
#include "UnitWidget.h"

class SpaceSectorDialog : public QDialog
{
    Q_OBJECT
public:
    SpaceSectorDialog(QWidget *parent = 0);
    SpaceSectorDialog(QString spaceSectorName, QWidget *parent = 0);

private:
    QBoxLayout* pbxLayout;

    QFile fSpaceSector;

    QPushButton* spaceShips;
    QMenu* menuSpaceShips;
    QAction* spaceShip;

    QPushButton* units;
    QMenu* menuUnits;
    QAction* unit;

    QPushButton* cancel;

signals:

public slots:
};

#endif // SPACESECTORDIALOG_H
