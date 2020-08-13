#include <SFML/Graphics.hpp>


class SpeedPowerUp
{

private:

	sf::Sprite * m_speedpowerup;
	sf::Texture texture;
	float originalPosX, originalPosY;
	float moveX, moveY;
public:
	SpeedPowerUp(sf::Vector2f size);
	void Move(sf::Vector2f p_speed);

	void ChangeDirection(sf::Vector2f p_change);


	~SpeedPowerUp();

	sf::Sprite * GetSprite();


};
