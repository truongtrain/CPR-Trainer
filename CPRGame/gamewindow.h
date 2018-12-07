#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QBrush>
#include <QString>
#include "gamestate.h"
#include "cpr_model.h"
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0, CPR_Model *model = new CPR_Model());
    ~GameWindow();
    GameState* gameState;

private:
    Ui::GameWindow *ui;

    //  Selection region for neck
    QPoint neckTopLeft;
    QPoint neckBottomRight;

    QPoint chestTopLeft;
    QPoint chestBottomRight;
    QPoint AED_Pad1_TopLeft;
    QPoint AED_Pad1_BottomRight;
    QPoint AED_Pad2_TopLeft;
    QPoint AED_Pad2_BottomRight;

    bool isCheckingPulseAndBreath;
    bool isDoingCompression;
    bool isDoingAEDPad1;
    bool isDoingAEDPad2;

    QPixmap loadPulse;
    QPixmap loadHandUp;
    QPixmap loadHandDown;

    QPixmap cursorAEDPads;
    QPixmap appliedAEDPads;

    QPixmap overlayImage;
    QPixmap baseImage;

    int totalAppliedPads;

    QMatrix rotateImage;

    QCursor newCursorImage;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void on_callAction_clicked();
    void on_cprAction_clicked();
    void on_breathAction_clicked();
    void on_checkResponseAction_clicked();
    void on_checkBreathAction_clicked();
    void SetStatusBox(string s);
    void SetTutorialBox(string s);
    void toggleAEDSlot(bool toggle);

    void on_AEDPowerButton_clicked();

    void on_pushButton_6_clicked();

    void on_shoutClear_clicked();

    void on_padsButton_clicked();

    void on_playAgainButton_released();

    void on_tryAgainButton_released();

    void on_checkBreathAndPulseButton_clicked();

    void setCursorToDefault();

    void on_playAgainButton_clicked();

    void on_tryAgainButton_clicked();

signals:
    void action(int state);
};
#endif // GAMEWINDOW_H
