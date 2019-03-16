#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>

namespace Ui {
class chartWindow;
}

class chartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit chartWindow(QWidget *parent = nullptr);
    ~chartWindow();

private:
    Ui::chartWindow *ui;
};

#endif // CHARTWINDOW_H
