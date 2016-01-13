#include "SpaceSectorDialog.h"

SpaceSectorDialog::SpaceSectorDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    qDebug()<<"SpaceSectorDialog::SpaceSectorDialog(QWidget *parent) : QWidget(parent)";
}

SpaceSectorDialog::SpaceSectorDialog(QString spaceSectorName, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);
    setWindowTitle("SpaceSector " + spaceSectorName);

    spaceShips = new QPushButton("SpaceShips");
    pbxLayout->addWidget(spaceShips, 1);
    spaceShips->setObjectName("spaceShips");
    menuSpaceShips = new QMenu();
    spaceShips->setMenu(menuSpaceShips);

    units = new QPushButton("Units");
    pbxLayout->addWidget(units);
    units->setObjectName("units");
    menuUnits = new QMenu();
    units->setMenu(menuUnits);

    fSpaceSector.setFileName(spaceSectorName+".txt");
    if (fSpaceSector.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSpaceSector);
        str;
        while (!stream.atEnd())
        {
            str = stream.readLine();
            if (str[0]=='S')
            {
                spaceShip = new QAction(str, spaceShips);
                QObject::connect(spaceShip, SIGNAL(triggered()), this, SLOT(createSpaceShipDialog()));
                menuSpaceShips->addAction(spaceShip);
                qDebug()<<str;
            }
            if (str[0]=='U')
            {
                unit = new QAction(str, units);
                menuUnits->addAction(unit);
                qDebug()<<str;
            }


        }
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"???·??a”¬??a•¦??a• ??a•???a•? ??a”¤??a”???a•???????a•¦??a–? ??a””??a•???a•§??a•©??a•?";
        }
        fSpaceSector.close();
    }

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));

}

void SpaceSectorDialog::createSpaceShipDialog()
{
    spaceShipDialog=new SpaceShipDialog(str);
    spaceShipDialog->show();
}
