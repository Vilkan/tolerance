#include "SpaceShipDialog.h"

SpaceShipDialog::SpaceShipDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

}

SpaceShipDialog::SpaceShipDialog(QString spaceShipName, QWidget* pwgt/*= 0*/) : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);
    this->setMinimumSize(200, 200);
    setWindowTitle(spaceShipName);

    QString s = "spaceShipInformation";
    QLabel* l = new QLabel(s);
    pbxLayout->addWidget(l);

    cancel = new QPushButton("Cancel");
    pbxLayout->addWidget(cancel);
    cancel->setObjectName("cancel");
    QObject::connect(this->findChild<QObject*>("cancel"), SIGNAL(clicked()), this, SLOT(hide()));
}
