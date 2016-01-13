#ifndef SPACESHIPDIALOG_H
#define SPACESHIPDIALOG_H

#include <QtWidgets>

class SpaceShipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpaceShipDialog(QWidget *parent = 0);
    SpaceShipDialog(QString spaceSectorName, QWidget *parent = 0);

private:
    QBoxLayout* pbxLayout;

    QPushButton* cancel;
    
signals:
    
public slots:
    
};

#endif // SPACESHIPDIALOG_H
