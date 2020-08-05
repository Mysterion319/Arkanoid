

#include <SFML/Graphics.hpp>

class Paddle
{

private:

	sf::Sprite * m_paddle;
	sf::Texture texture;
	sf::Vector2f velocity;








public:
	Paddle(sf::Vector2f size);
	void Move(sf::Event event);
	sf::Sprite* GetSprite();


	~Paddle();
};
