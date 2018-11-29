#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <math.h>
#include <QImage>
#include <QDebug>

WelcomeScreen::WelcomeScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeScreen)
{
    ui->setupUi(this);


    // Set up the Box2D world in which the animation takes place
    Gravity = new b2Vec2(0.f, 9.8f);
    World = new b2World(*Gravity);
    animationSizeX = 800;
    animationSizeY = 600;

    ui->animationLabel->resize(animationSizeX, animationSizeY);
    this->setFixedSize(animationSizeX, animationSizeY);

    // Setup the textures
    texture.create(animationSizeX,animationSizeY);    // Probably the size of our screen? TODO: figure this out.
    ambulanceTexture.loadFromFile("../Resources/Ambulance32x32.png"); // TODO.  Figure out how to access this through resources.qrc
    groundTexture.loadFromFile("../Resources/MarioGround.png"); // TODO.  Figure out how to access this through resources.qrc
    ambulanceTexture.setSmooth(true);
    groundTexture.setSmooth(true);

    // Create the ground
    createGround(animationSizeX/2, animationSizeY - 100);   // Center of screen. Offset from bottom of screen by 100 pixels.

    // Create a single ambulance
    // generateAmbulance(200.f, 200.f, 0, 180.f); // Buggy. Does not draw ground when uncommented.

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WelcomeScreen::renderTexture);
    timer->start(1);

    qDebug() << "This point successfully reached";
}

WelcomeScreen::~WelcomeScreen()
{
    delete World;
    delete Gravity;
    delete ui;
}

void WelcomeScreen::renderTexture(){
    texture.clear(sf::Color::Blue);

    for (b2Body* BodyIterator = World->GetBodyList();
         BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
    {
        if (BodyIterator->GetType() == b2_dynamicBody)
        {
            sprite.setTexture(ambulanceTexture);
            sprite.setOrigin(16.f, 16.f);
            sprite.setPosition(BodyIterator->GetPosition().x,
                               BodyIterator->GetPosition().y);
            sprite.setRotation(BodyIterator->GetAngle()* 180/b2_pi);
            texture.draw(sprite);
            qDebug() << "Drawing ambulance";
        }
        else
        {
            sprite.setTexture(groundTexture);
            sprite.setOrigin(823.f, 122.f);
            sprite.setPosition(BodyIterator->GetPosition().x,
                                     BodyIterator->GetPosition().y);
            sprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
            texture.draw(sprite);
            qDebug() << "Drawing ground";
        }
    }

    texture.display();

    // Set to a QImage
    sf::Texture rt = texture.getTexture();
    sf::Image irt = rt.copyToImage();
    const uint8_t *pp = irt.getPixelsPtr();
    QImage qi(pp, animationSizeX, animationSizeY, QImage::Format_ARGB32);
    qi = qi.rgbSwapped();
    ui->animationLabel->setPixmap(QPixmap::fromImage(qi));

}


void WelcomeScreen::createGround(float X, float Y)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(X, Y);
    BodyDef.type = b2_staticBody;
    b2Body* Body = World->CreateBody(&BodyDef);

    b2PolygonShape Shape;
    sf::Vector2u textureSize = groundTexture.getSize();
    float sizeX = textureSize.x;
    float sizeY = textureSize.y;
    Shape.SetAsBox(sizeX, sizeY);

    qDebug() << "X:" << textureSize.x << " . Y:" << textureSize.y;
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}

void WelcomeScreen::generateAmbulance(float posX, float posY, float velocity, float angleDegrees)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(posX, posY);
    BodyDef.type = b2_dynamicBody;
    float velocityX = cos(angleDegrees*3.14159265/180);
    float velocityY = sin(angleDegrees*3.14159265/180);
    BodyDef.linearVelocity = b2Vec2(velocityX, velocityY);
    b2Body* Body = World->CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((32.f/2), (32.f/2));  // TODO: Link this to the shape of the smbulance texture, not fixed numbers.
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}
