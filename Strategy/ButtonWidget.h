#ifndef ButtonWidget_H
#define ButtonWidget_H

//#include <QtWidgets>
#include <QtGui>

class ButtonWidget : public QWidget
{
        Q_OBJECT

        public:
            ButtonWidget(QWidget *parent = 0);

        private:
                QPalette pal1;
                QBoxLayout* pbxLayout;

                QPushButton* call;
                QMenu* menuCall;

                QPushButton* send;
                QMenu* menuSend;

                QAction* number;
                QFile fNumbers;

                QPushButton* end;
                QMenu* menuEnd;
                QAction *day;
                QAction *period;

                QPushButton* menu;
                QMenu* menuMenu;
                QAction* repaint;
                QAction* save;
                QAction* exit;

};
#endif//ButtonWidget_H
