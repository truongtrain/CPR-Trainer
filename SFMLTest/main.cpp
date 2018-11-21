
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    window.setFramerateLimit(24);
    // Load a sprite to display
    vector<sf::Texture> textures(2);
    if (!textures[0].loadFromFile("../SFMLTest/icon.png")) {
        return EXIT_FAILURE;
    }

    if (!textures[1].loadFromFile("../SFMLTest/icon2.png")) {
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
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();
  //      sprite.move(4.0,3.0);
        sprite.rotate(1.0);
        // Draw all the sprites. Usually it is good to
        // update things all at once, then draw all at once.
        window.draw(sprite);
        sprite.setTexture(textures[(imageNum/20)%2]);
        imageNum++;
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}




