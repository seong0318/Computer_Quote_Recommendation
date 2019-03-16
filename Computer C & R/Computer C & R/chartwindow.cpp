#include "chartwindow.h"
#include "ui_chartwindow.h"

chartWindow::chartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chartWindow)
{
    ui->setupUi(this);
}

chartWindow::~chartWindow()
{
    delete ui;
}
