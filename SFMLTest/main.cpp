
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <vector>
using namespace std;

void CreateGround(b2World& World, float X, float Y);

void CreateBox(b2World& World, int MouseX, int MouseY);

int main(int, char const**)
{
    const float SCALE = 30.f;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    window.setFramerateLimit(24);

    // Prepare the world
    b2Vec2 Gravity(0.f, 9.8f);
    b2World World(Gravity);
    float x = 400.f;
    float y = 500.f;
    CreateGround(World, x, y);



    // Load a sprite to display
    vector<sf::Texture> textures(2);
    if (!textures[0].loadFromFile("../SFMLTest/vader.png")) {
        return EXIT_FAILURE;
    }

    if (!textures[1].loadFromFile("../SFMLTest/deathStar.jpeg")) {
        return EXIT_FAILURE;
    }
    textures[0].setSmooth(true);
    textures[1].setSmooth(true);
    // Create the sprite
    sf::Sprite sprite(textures[0]);

    sprite.setOrigin(200,100);
    sprite.setPosition(400,300);
    sf::Music music;
    if (!music.openFromFile("../SFMLTest/Imperial_March.ogx")) {

        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    // Use this counter to cycle through sprite frames.
    int imageNum = 0;
    // Start the game loop
    while (window.isOpen())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            int MouseX = sf::Mouse::getPosition(window).x;
            int MouseY = sf::Mouse::getPosition(window).y;
            CreateBox(World, MouseX, MouseY);

        }

        //Simulate the world
        World.Step(1/60.f, 8, 3);

        window.clear(sf::Color::White);
        for (b2Body* BodyIterator = World.GetBodyList();
             BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {
                sf::Sprite Sprite;
                Sprite.setTexture(textures[0]);
                Sprite.setOrigin(200.f, 200.f);
                Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE *
                                   BodyIterator->GetPosition().y);
                Sprite.setRotation(BodyIterator->GetAngle()* 180/b2_pi);
                window.draw(Sprite);
            }
            else
            {
                sf::Sprite groundSprite;
                groundSprite.setTexture(textures[0]);
                groundSprite.setOrigin(400.f, 8.f);
                groundSprite.setPosition(BodyIterator->GetPosition().x * SCALE,
                                         BodyIterator->GetPosition().y * SCALE);
                groundSprite.setRotation(180/b2_pi * BodyIterator->GetAngle());
                window.draw(groundSprite);
            }
        }

        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }

//        // Clear screen
//        window.clear();
//  //      sprite.move(4.0,3.0);
//        sprite.rotate(1.0);
//        // Draw all the sprites. Usually it is good to
//        // update things all at once, then draw all at once.
//        window.draw(sprite);
//        sprite.setTexture(textures[(imageNum/20)%2]);
//        imageNum++;
//        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

void CreateGround(b2World& World, float X, float Y)
{
    const float SCALE = 30.f;

    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(X/SCALE, Y/SCALE);
    BodyDef.type = b2_staticBody;
    b2Body* Body = World.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((800.f/2)/SCALE, (16.f/2)/SCALE);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}

void CreateBox(b2World& World, int MouseX, int MouseY)
{
    const float SCALE = 30.f;

    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(MouseX/SCALE, MouseY/SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = World.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}






