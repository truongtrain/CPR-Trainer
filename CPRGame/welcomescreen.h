#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QMainWindow>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <random>

namespace Ui {
class WelcomeScreen;
}

class WelcomeScreen : public QMainWindow
{
    Q_OBJECT



public:
    explicit WelcomeScreen(QWidget *parent = 0);
    ~WelcomeScreen();

private slots:
    void on_startButton_clicked();

private:
    Ui::WelcomeScreen *ui;
    sf::RenderTexture texture;
    sf::Texture ambulanceTexture;
    sf::Texture groundTexture;
    sf::Sprite sprite;
    QTimer *frameRefreshTimer;
    QTimer *generateAmbulanceTimer;
    int animationSizeX;
    int animationSizeY;
    const int SCALE = 8;
    const int FRAME_RATE = 32;

    b2Vec2 * Gravity;
    b2World * World;

    void renderTexture();
    void createGround(float X, float Y);
    void generateRandomAmbulance();
    void generateAmbulance(float posX, float posY,
                           float velocity, float velocityAngleDegrees,
                           float initialAngleDegrees, float rotationSpeed);


signals:
    void startButtonClicked();
};

#endif // WELCOMESCREEN_H
