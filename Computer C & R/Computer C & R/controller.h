#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "allpartandgamedata.h"
#include "usergameselection.h"
#include "userpartselection.h"
#include "mainwindow.h"

class Controller {
public:
    AllPartAndGameData *apag;
    MainWindow *w;
    UserPartSelection *ups;
    UserGameSelection *ugs;
    QApplication *a;
    Controller();
};

#endif // CONTROLLER_H
