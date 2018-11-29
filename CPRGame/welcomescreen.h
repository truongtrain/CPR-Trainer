#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QMainWindow>
#include <QTimer>
#include <SFML/Graphics.hpp>

namespace Ui {
class WelcomeScreen;
}

class WelcomeScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeScreen(QWidget *parent = 0);
    ~WelcomeScreen();

private:
    Ui::WelcomeScreen *ui;
    sf::RenderTexture texture;
    sf::Texture ambulanceTexture;
    sf::Texture groundTexture;
    sf::Sprite sprite;
    QTimer *timer;

    void renderTexture();

    void createGround();
    void createAmbulance();
};

#endif // WELCOMESCREEN_H
