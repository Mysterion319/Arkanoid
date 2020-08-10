#include <SFML/Graphics.hpp>


class Ball
{

private:

	sf::Sprite * m_ball;
	sf::Texture texture;
	float originalPosX, originalPosY;
	float moveX, moveY;
public:
	Ball(sf::Vector2f size);
	void Move(sf::Vector2f p_speed);
	void Rotate(float rotation);
	void ChangeDirection(sf::Vector2f p_change);
	
	
	~Ball();
	
	sf::Sprite * GetSprite();


};
