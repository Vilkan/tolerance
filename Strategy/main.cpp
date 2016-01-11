#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;


    QObject::connect(w.findChild<QObject*>("bw")->findChild<QObject*>("exit"), SIGNAL(triggered()), &a, SLOT(quit()));

    w.show();
    return a.exec();
}
