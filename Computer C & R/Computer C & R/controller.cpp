#include "controller.h"

Controller::Controller(){
    AllPartAndGameData *apagg = new AllPartAndGameData;
    this->apag = apagg;
    apag->openPartFiles();
    apag->openGameFiles();

    UserPartSelection *ups = new UserPartSelection(apagg);
    UserGameSelection *ugs = new UserGameSelection(apagg);

    MainWindow *w = new MainWindow(ups, ugs);

    ups->registerObserver(w);
    ugs->registerObserver(w);
    ups->initializeUserPartSelectableList();
    ugs->initializeUserGameSelectableList();

    w->show();
}
