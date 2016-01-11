#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

//#include <QtWidgets>
#include <QtGui>

class StatisticWidget : public QWidget
{
        Q_OBJECT

        public:
            StatisticWidget(QWidget *parent = 0);

        private:
            QPalette pal1;
            QBoxLayout* pbxLayout;

            QBoxLayout* resourceLayout;
            QFile fResource;

            QBoxLayout* lifeLayout;
            QWidget* wLife;
            QPalette lifePall;
            int iLife;
            QString sLife;
            QLabel* lLife;

            QBoxLayout* distructionLayout;
            QWidget* wDistruction;
            QPalette distructionPall;
            int iDistruction;
            QString sDistruction;
            QLabel* lDistruction;

            QBoxLayout* creationLayout;
            QWidget* wCreation;
            QPalette creationPall;
            int iCreation;
            QString sCreation;
            QLabel* lCreation;

            QBoxLayout* absLayout;
            QWidget* wAbs;
            QPalette absPall;
            int iAbs;
            QString sAbs;
            QLabel* lAbs;

            QBoxLayout* dateLayout;
            QFile fDate;
            int iDay;
            QString sDay;
            int iPeriod;
            QString sPeriod;
            QLabel* lDate;

            void saveDate();
            void saveResources();


        public slots:
            void slotIncDay();
            void slotIncPeriod();
            void slotSave();

};

#endif // STATISTICWIDGET_H
