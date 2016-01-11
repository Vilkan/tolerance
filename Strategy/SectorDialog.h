#ifndef SECTORDIALOG_H
#define SECTORDIALOG_H

//#include <QtWidgets>
#include <QtGui>

class SectorDialog : public QDialog
{
    Q_OBJECT
public:
    SectorDialog(QWidget *parent = 0);
    SectorDialog(QString str, QWidget *parent = 0);

private:
    QBoxLayout* pbxLayout;

    QString sectorInfo;
    QString sectorName;
    QString sectorWays;
    QString sectorPlanets;

    QPushButton* spaceSector;
    QPushButton* planetSectors;
    QPushButton* cancel;

signals:

public slots:
};

#endif // SECTORDIALOG_H
