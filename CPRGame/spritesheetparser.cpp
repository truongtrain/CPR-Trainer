#include "spritesheetparser.h"

SpriteSheetParser::SpriteSheetParser()
{

}

std::vector<sf::Texture> SpriteSheetParser::parseFromSheet(sf::Texture sheet, int rows, int cols, int textureCount)
{
    std::vector<sf::Texture> textures;
    sf::Vector2u sheetSize = sheet.getSize();
    sf::Image imageGrid = sheet.copyToImage();


    int spriteWidth = sheetSize.x/cols;
    int spriteHeight = sheetSize.y/rows;
    int spriteLeftX = 0;
    int spriteTopY = 0;


    int texturesAdded = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            // Set up area on the sprite sheet where desired image is.
            sf::IntRect rect(spriteLeftX, spriteTopY, spriteWidth, spriteHeight);
            sf::Texture newTexture;
            newTexture.loadFromImage(imageGrid, rect);
            textures.push_back(newTexture);
            texturesAdded ++;
            spriteLeftX += spriteWidth; // Set X for next row.

            if (texturesAdded >= textureCount)
                break;
        }
        spriteLeftX = 0; // Reset X to zero for next row.
        spriteTopY += spriteHeight; // Set Y for next column.

        if (texturesAdded >= textureCount)
            break;
    }

    return textures;
}
