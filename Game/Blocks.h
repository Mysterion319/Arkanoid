#include <Vector>
#include <SFML/Graphics.hpp>
using std::vector;

class Blocks
{

private:

	sf::Sprite * m_blocks;
	sf::Texture blockTexture;
	float originalPosX, originalPosY;
	/*float  BallSetScaleX;
	float  BallSetScaleY;
	float  BallSetPositionX;
	float  BallSetPositionY;*/
	vector< sf::Sprite*> *blocks;
public:
	Blocks();
	~Blocks();
	vector< sf::Sprite*> *getblocks();
	


};