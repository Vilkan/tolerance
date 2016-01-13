#include "ButtonWidget.h"

ButtonWidget::ButtonWidget(QWidget *parent)
    : QWidget(parent)
{
    pal1.setColor(this->backgroundRole(), Qt::blue);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("bw");
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);


    call = new QPushButton("Call");
    pbxLayout->addWidget(call, 1);
    call->setObjectName("call");
    menuCall = new QMenu();
    call->setMenu(menuCall);
    //call->hide();

    send = new QPushButton("Send");
    pbxLayout->addWidget(send, 1);
    send->setObjectName("send");
    menuSend = new QMenu();
    send->setMenu(menuSend);
    //send->hide();

    fNumbers.setFileName("numbers.txt");
    if (fNumbers.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fNumbers);
        QString str;
        while (!stream.atEnd())
        {
            str = stream.readLine();
            number = new QAction(str, call);
            menuCall->addAction(number);
            number = new QAction(str, send);
            menuSend->addAction(number);
            qDebug()<<str;
        }
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"numbers fail";
        }
        fNumbers.close();
    }

    end = new QPushButton("End");
    pbxLayout->addWidget(end, 1);
    end->setObjectName("end");
    menuEnd = new QMenu();
    end->setMenu(menuEnd);

    day = new QAction(tr("Day"), end);
    menuEnd->addAction(day);
    day->setObjectName("day");

    period = new QAction(tr("Period"), end);
    menuEnd->addAction(period);
    period->setObjectName("period");


    menu = new QPushButton("Menu");
    pbxLayout->addWidget(menu, 1);
    menu->setObjectName("menu");
    menuMenu = new QMenu();
    menu->setMenu(menuMenu);

    repaint = new QAction(tr("Repaint"), menu);
    menuMenu->addAction(repaint);
    repaint->setObjectName("repaint");

    save = new QAction(tr("Save"), menu);
    menuMenu->addAction(save);
    save->setObjectName("save");

    exit = new QAction(tr("Exit"), menu);
    menuMenu->addAction(exit);
    exit->setObjectName("exit");

}






