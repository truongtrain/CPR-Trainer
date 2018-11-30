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
    qDebug() << "WelcomeScreen ui set up!";

    // Set up the Box2D world in which the animation takes place
    Gravity = new b2Vec2(0.f, 3.f/SCALE);
    World = new b2World(*Gravity);
    animationSizeX = 800;
    animationSizeY = 600;

    ui->animationLabel->resize(animationSizeX, animationSizeY);
    this->setFixedSize(animationSizeX, animationSizeY);

    // Setup the textures
    texture.create(animationSizeX, animationSizeY);    // Probably the size of our screen? TODO: figure this out.
    ambulanceTexture.loadFromFile("../Resources/Ambulance32x32.png"); // TODO.  Figure out how to access this through resources.qrc
    groundTexture.loadFromFile("../Resources/MarioGround.png"); // TODO.  Figure out how to access this through resources.qrc
    ambulanceTexture.setSmooth(true);
    groundTexture.setSmooth(true);

    // Create the ground
    createGround(animationSizeX/2, animationSizeY - 100);   // Center of screen. Offset from bottom of screen by 100 pixels.

    // Create some random ambulances
    for (int i = 0; i < 25; i++)
        generateRandomAmbulance();

    frameRefreshTimer = new QTimer(this);
    connect(frameRefreshTimer, &QTimer::timeout, this, &WelcomeScreen::renderTexture);
    frameRefreshTimer->start(1000/FRAME_RATE);

    // TODO:  Try and figure out why code crashes when connecting ambulance generation to a timer.
//    generateAmbulanceTimer = new QTimer(this);
//    connect(generateAmbulanceTimer, &QTimer::timeout, this, &WelcomeScreen::generateRandomAmbulance);
//    generateAmbulanceTimer->start(10000/FRAME_RATE);
}


WelcomeScreen::~WelcomeScreen()
{
    delete World;
    delete Gravity;
    delete ui;
}

void WelcomeScreen::renderTexture(){
    World->Step(0.1, 8, 3);

    texture.clear(sf::Color::Blue);

    for (b2Body* BodyIterator = World->GetBodyList();
         BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
    {
        if (BodyIterator->GetType() == b2_dynamicBody)
        {
            sf::Sprite ambulanceSprite;
            ambulanceSprite.setTexture(ambulanceTexture);
            ambulanceSprite.setOrigin(16.f, 16.f);
            int posX = BodyIterator->GetPosition().x*SCALE;
            int posY = BodyIterator->GetPosition().y*SCALE - 4;   // This offset allows the ambulances to pack together better
            ambulanceSprite.setPosition(posX, posY);
            ambulanceSprite.setRotation(BodyIterator->GetAngle()* 180/b2_pi);
            texture.draw(ambulanceSprite);
        }
        else
        {
            sf::Sprite groundSprite;
            groundSprite.setTexture(groundTexture);
            groundSprite.setOrigin(823.f, 122.f);
            int posX = BodyIterator->GetPosition().x*SCALE;
            int posY = BodyIterator->GetPosition().y*SCALE;
            groundSprite.setPosition(posX, posY);
            groundSprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
            texture.draw(groundSprite);
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
    BodyDef.position = b2Vec2(X/SCALE, Y/SCALE);
    BodyDef.type = b2_staticBody;
    b2Body* Body = World->CreateBody(&BodyDef);

    b2PolygonShape Shape;
    sf::Vector2u textureSize = groundTexture.getSize();
    float sizeX = textureSize.x/SCALE;
    float sizeY = textureSize.y/SCALE;
    Shape.SetAsBox(sizeX/2, sizeY/2); // The x and y specified appear to refer to the
                                      //   distance from the center to the edges.

    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}

void WelcomeScreen::generateRandomAmbulance()
{
    // Start boilder plate code.
    int upperLimit;
    int lowerLimit;
    int randX = std::rand() % (upperLimit - lowerLimit) + lowerLimit;
    // End boiler plate code.

    // Value used when generating ambulance
    int xPos, yPos, v, vAngle, angularVelocity;

    // Values TBD based on direction from which ambulance enters screen.
    int xPosMin, xPosMax, yPosMin, yPosMax;
    int vAngleMin, vAngleMax;

    // TBD what good numbers are
    int vMin = 64;
    int vMax = 80;
    int angularVelocityMin = 1;
    int angularVelocityMax = 5;

    // Choose a direction from which an ambulance enters the screen
    int directionDecider = std::rand() % 2;
    if (directionDecider == 0)
    {
        // Ambulance appears from left side of screen
        xPosMin = -100;
        xPosMax = -50;
        yPosMin = 0;
        yPosMax = animationSizeY/2;
        vAngleMin = 0;
        vAngleMax = 60;
        qDebug() << "Left ----------";
    }
    else if (directionDecider == 1)
    {
        // Ambulance appears from right side of screen
        xPosMin = animationSizeX + 50;
        xPosMax = animationSizeX + 100;
        yPosMin = 0;
        yPosMax = animationSizeY/2;
        vAngleMin = 180;
        vAngleMax = 240;
        qDebug() << "Right ";
    }

    // Generate the random values.
    xPos = std::rand() % (xPosMax - xPosMin) + xPosMin;
    yPos = std::rand() % (yPosMax - yPosMin) + yPosMin;
    v = std::rand() % (vMax - vMin) + vMin;
    vAngle = std::rand() % (vAngleMax - vAngleMin) + vAngleMin;
    angularVelocity = std::rand() % (angularVelocityMax - angularVelocityMin) + angularVelocityMin;

    // Create am ambulance.
    generateAmbulance((float)xPos, (float)yPos, (float)v, (float)vAngle, 0.f, (float)angularVelocity);
}

void WelcomeScreen::generateAmbulance(float posX, float posY,
                                      float velocity, float velocityAngleDegrees,
                                      float initialAngleDegrees, float rotationSpeed)
{
    b2BodyDef BodyDef;
    BodyDef.type = b2_dynamicBody;
    BodyDef.position = b2Vec2(posX/SCALE, posY/SCALE);
    float velocityX = velocity/SCALE * cos(velocityAngleDegrees*3.14159265/180);
    float velocityY = velocity/SCALE * sin(velocityAngleDegrees*3.14159265/180);
    // qDebug() << "Ambulance vX: " << velocityX << " vY: " << velocityY;
    BodyDef.linearVelocity = b2Vec2(velocityX, velocityY);
    BodyDef.angularVelocity = rotationSpeed;
    BodyDef.angle = initialAngleDegrees*3.14159265/180;
    b2Body* Body = World->CreateBody(&BodyDef);

    b2PolygonShape Shape;
    sf::Vector2u textureSize = ambulanceTexture.getSize();
    float sizeX = textureSize.x/SCALE;
    float sizeY = (textureSize.y*.85)/SCALE; // Not just y/SCALE because ambulances pack together better with this value.
    Shape.SetAsBox(sizeX/2, sizeY/2);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}

void WelcomeScreen::on_startButton_clicked()
{
    emit startButtonClicked();
    this->close();
}
