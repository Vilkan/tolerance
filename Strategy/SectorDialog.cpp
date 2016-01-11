#include "SectorDialog.h"

SectorDialog::SectorDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    qDebug()<<"SectorDialog::SectorDialog(QWidget *parent) : QWidget(parent)";
}

SectorDialog::SectorDialog(QString str, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);

    sectorInfo=str;
    int pos=0;
    bool flag=false;
    for (int i=0; i<sectorInfo.size(); i++)
    {
        if ((flag==true)&&(sectorInfo.at(i)!=' ')&&(sectorInfo.at(i)!=';'))
        {
            if (pos==0) sectorName.append(sectorInfo.at(i));
            if (pos==1) sectorWays.append(sectorInfo.at(i));
            if (pos==2) sectorPlanets.append(sectorInfo.at(i));
        }
        if ((flag==true)&&(sectorInfo.at(i)==';'))
        {
            pos++;
            flag=false;
        }
        if ((flag==false)&&(sectorInfo.at(i)==':')) flag=true;
    }
    qDebug()<<"sectorName="<<sectorName;
    qDebug()<<"sectorWays="<<sectorWays;
    qDebug()<<"sectorPlanets="<<sectorPlanets;

    spaceSector = new QPushButton("SpaceSector");
    pbxLayout->addWidget(spaceSector);
    spaceSector->setObjectName("spaceSector");
    QObject::connect(this->findChild<QObject*>("spaceSector"), SIGNAL(clicked()), this, SLOT(hide()));

    planetSectors = new QPushButton("PlanetSectors");
    pbxLayout->addWidget(planetSectors);
    planetSectors->setObjectName("planetSectors");
    //QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));

}
