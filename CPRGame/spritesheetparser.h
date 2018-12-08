#ifndef SPRITESHEETPARSER_H
#define SPRITESHEETPARSER_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <QDebug>

/**
 * This is the SpriteSheetParser class.
 * A SpriteSheetParser converts an image grid into a vector of the images that
 * the image grid consists of.
 */
class SpriteSheetParser
{
public:
    SpriteSheetParser();
    ~SpriteSheetParser();

    /**
     * Converts an image grid, sheet, into a vector of the images that sheet consists of.
     * sheet must be an SFML Textue.
     * the size of sheet is rows x cols
     * the number of images in sheet is count
     */
    static std::vector<sf::Texture> parseFromSheet(sf::Texture sheet, int rows, int cols, int count);


};

#endif // SPRITESHEETPARSER_H
