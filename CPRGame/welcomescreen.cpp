#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <QImage>
#include <QDebug>

WelcomeScreen::WelcomeScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeScreen)
{
    ui->setupUi(this);

    // Set up the Box2D world in which the animation takes place


    // Setup the textures
    texture.create(500,400);    // Probably the size of our screen? TODO: figure this out.
    ambulanceTexture.loadFromFile("../Resources/Ambulance32x32.png"); // TODO.  Figure out how to access this through resources.qrc
    groundTexture.loadFromFile("../Resources/MarioGround.png"); // TODO.  Figure out how to access this through resources.qrc
    ambulanceTexture.setSmooth(true);
    groundTexture.setSmooth(true);

    // Create the sprite
    sf::Sprite sprite(ambulanceTexture);

    sprite.setOrigin(200, 100);
    sprite.setPosition(400,300);    // TODO.  See if these two lines can be deleted later

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WelcomeScreen::renderTexture);
    timer->start(1);

    qDebug() << "This point successfully reached";
}

WelcomeScreen::~WelcomeScreen()
{
    delete ui;
}

void WelcomeScreen::renderTexture(){
    texture.clear(sf::Color::Blue);

    // Set up each ambulance here, then call the below line.
    texture.draw(sprite);

    texture.display(); // Goes at the very end

    // Set to a QImage
    sf::Texture rt = texture.getTexture();
    sf::Image irt = rt.copyToImage();
    const uint8_t *pp = irt.getPixelsPtr();
    QImage qi(pp, 500, 400, QImage::Format_ARGB32);
    qi = qi.rgbSwapped();
    ui->animationLabel->setPixmap(QPixmap::fromImage(qi));

}
