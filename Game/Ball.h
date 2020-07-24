#include <SFML/Graphics.hpp>
#include <array>

using std::array;


class Ball
{

private:

	sf::Sprite * m_ball;
	sf::Texture texture;
	float originalPosX, originalPosY;

public:
	Ball(sf::Vector2f size);
	~Ball();

	sf::Sprite * GetSprite();


};
