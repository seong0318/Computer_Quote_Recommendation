#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "allpartandgamedata.h"
#include "userpartselection.h"
#include "usergameselection.h"
#include "controller.h"
using namespace std;

int main(int argc, char *argv[]) {

    srand((unsigned int)time(nullptr));
    QApplication a(argc, argv);
    Controller *c = new Controller();

    return a.exec();
}
