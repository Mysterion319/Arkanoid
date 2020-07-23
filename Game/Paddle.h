

#include <SFML/Graphics.hpp>

class Paddle
{

private:

	sf::Sprite * m_paddle;
	sf::Texture texture;

public:
	Paddle(sf::Vector2f size);

	sf::Sprite* GetSprite();


	~Paddle();
};
