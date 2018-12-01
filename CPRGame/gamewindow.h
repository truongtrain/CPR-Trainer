#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;


protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_minimize_released();
    void on_proOff_released();
    void on_proOn_released();
};
#endif // GAMEWINDOW_H
