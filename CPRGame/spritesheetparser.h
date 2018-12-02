#ifndef SPRITESHEETPARSER_H
#define SPRITESHEETPARSER_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <QDebug>


class SpriteSheetParser
{
public:
    SpriteSheetParser();
    ~SpriteSheetParser();
    static std::vector<sf::Texture> parseFromSheet(sf::Texture sheet, int rows, int cols, int count);


};

#endif // SPRITESHEETPARSER_H
