#include "StatisticWidget.h"

StatisticWidget::StatisticWidget(QWidget *parent)
    : QWidget(parent)
{
    pal1.setColor(this->backgroundRole(), Qt::yellow);
    this->setPalette(pal1);
    this->setAutoFillBackground(true);
    this->setObjectName("sw");

    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    this->setLayout(pbxLayout);

    fResource.setFileName("resources.txt");
    if (fResource.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fResource);
        QString str;
        str = stream.readLine();
        iLife = str.toInt();
        qDebug()<<"StatisticWidget::StatisticWidget: Life="<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = stream.readLine();
        iDistruction = str.toInt();
        qDebug()<<"StatisticWidget::StatisticWidget: Distruction="<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = stream.readLine();
        iCreation = str.toInt();
        qDebug()<<"StatisticWidget::StatisticWidget: Creation="<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = stream.readLine();
        iAbs = str.toInt();
        qDebug()<<"StatisticWidget::StatisticWidget: Abs="<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }

        fResource.close();
    }


    resourceLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addLayout(resourceLayout, 1);

    lifeLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    resourceLayout->addLayout(lifeLayout, 1);
    wLife = new QWidget(this);
    lifeLayout->addWidget(wLife, 10);
    wLife->setFixedSize(15, 15);
    wLife->setToolTip("Life energy");
    lifePall.setColor(wLife->backgroundRole(), Qt::green);
    wLife->setPalette(lifePall);
    wLife->setAutoFillBackground(true);
    sLife = QString::number(iLife);
    lLife = new QLabel(sLife);
    lifeLayout->addWidget(lLife, 1);

    distructionLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    resourceLayout->addLayout(distructionLayout, 1);
    wDistruction = new QWidget(this);
    distructionLayout->addWidget(wDistruction, 10);
    wDistruction->setFixedSize(15, 15);
    wDistruction->setToolTip("Distruction energy");
    distructionPall.setColor(wDistruction->backgroundRole(), Qt::red);
    wDistruction->setPalette(distructionPall);
    wDistruction->setAutoFillBackground(true);
    sDistruction = QString::number(iDistruction);
    lDistruction = new QLabel(sDistruction);
    distructionLayout->addWidget(lDistruction, 1);

    creationLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    resourceLayout->addLayout(creationLayout, 1);
    wCreation = new QWidget(this);
    creationLayout->addWidget(wCreation, 10);
    wCreation->setFixedSize(15, 15);
    wCreation->setToolTip("Struction energy");
    creationPall.setColor(wCreation->backgroundRole(), Qt::blue);
    wCreation->setPalette(creationPall);
    wCreation->setAutoFillBackground(true);
    sCreation = QString::number(iCreation);
    lCreation = new QLabel(sCreation);
    creationLayout->addWidget(lCreation, 1);

    absLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    resourceLayout->addLayout(absLayout, 1);
    wAbs = new QWidget(this);
    absLayout->addWidget(wAbs, 10);
    wAbs->setFixedSize(15, 15);
    wAbs->setToolTip("Absolute energy");
    absPall.setColor(wAbs->backgroundRole(), Qt::white);
    wAbs->setPalette(absPall);
    wAbs->setAutoFillBackground(true);
    sAbs = QString::number(iAbs);
    lAbs = new QLabel(sAbs);
    absLayout->addWidget(lAbs, 1);


    fDate.setFileName("date.txt");
    if (fDate.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fDate);
        QString str;
        str = stream.readLine();
        iDay = str.toInt();
        qDebug()<<"StatisticWidget::StatisticWidget: Dat="<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = stream.readLine();
        iPeriod = str.toInt();
        qDebug()<<"StatisticWidget::StatisticWidget: Period="<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fDate.close();
    }

    dateLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addLayout(dateLayout, 1);
    sDay = QString::number(iDay);
    sPeriod = QString::number(iPeriod);
    lDate = new QLabel("Day " + sDay + "  Period " + sPeriod);
    dateLayout->addWidget(lDate, 1);

    QObject::connect(this->parent()->findChild<QObject*>("bw")->findChild<QObject*>("day"), SIGNAL(triggered()), this, SLOT(slotIncDay()));
    QObject::connect(this->parent()->findChild<QObject*>("bw")->findChild<QObject*>("period"), SIGNAL(triggered()), this, SLOT(slotIncPeriod()));

    QObject::connect(this->parent()->findChild<QObject*>("bw")->findChild<QObject*>("save"), SIGNAL(triggered()), this, SLOT(slotSave()));
}

void StatisticWidget::slotIncDay()
{
        iDay++;
        sDay = QString::number(iDay);
        lDate->setText("Day " + sDay + "  Period " + sPeriod);
}

void StatisticWidget::slotIncPeriod()
{
            iDay = 1;
            sDay = QString::number(iDay);

            iPeriod++;
            sPeriod = QString::number(iPeriod);
            lDate->setText("Day " + sDay + "  Period " + sPeriod);
}

void StatisticWidget::slotSave()
{
    saveDate();
    saveResources();
}

void StatisticWidget::saveDate()
{
    if (fDate.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fDate);
        QString str;
        str = QString::number(iDay);
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(iPeriod);
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fDate.close();
    }
}

void StatisticWidget::saveResources()
{
    if (fResource.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fResource);
        QString str;
        str = QString::number(iLife);
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(iDistruction);
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(iCreation);
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(iAbs);
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fResource.close();
    }
}
