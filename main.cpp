#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication mainApp(argc, argv);
    MainWidget *mainWidget = new MainWidget;
    mainWidget->show();
    mainWidget->run();

    return mainApp.exec();
}
