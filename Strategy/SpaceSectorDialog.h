#ifndef SPACESECTORDIALOG_H
#define SPACESECTORDIALOG_H

#include <QtWidgets>
#include <QtGui>
#include "SpaceShipDialog.h"
#include "UnitDialog.h"

class SpaceSectorDialog : public QDialog
{
    Q_OBJECT
public:
    SpaceSectorDialog(QWidget *parent = 0);
    SpaceSectorDialog(QString spaceSectorName, QWidget *parent = 0);

private:
    QBoxLayout* pbxLayout;

    QFile fSpaceSector;
    QString str;

    QPushButton* spaceShips;
    QMenu* menuSpaceShips;
    QAction* spaceShip;

    QPushButton* units;
    QMenu* menuUnits;
    QAction* unit;

    QPushButton* cancel;

    SpaceShipDialog* spaceShipDialog;

signals:

public slots:
    void createSpaceShipDialog();
};

#endif // SPACESECTORDIALOG_H
