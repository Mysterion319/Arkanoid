#include <array>
#include <SFML/Graphics.hpp>
using std::array;

class Blocks
{

private:

	sf::Sprite * m_blocks;
	sf::Texture blockTexture;
	float originalPosX, originalPosY;
	array< sf::Sprite*, 100> blocks;
public:
	Blocks();
	~Blocks();
	array< sf::Sprite*, 100> getblocks();
	


};
