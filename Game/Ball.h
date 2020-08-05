#include <SFML/Graphics.hpp>


class Ball
{

private:

	sf::Sprite * m_ball;
	sf::Texture texture;
	float originalPosX, originalPosY;

public:
	Ball(sf::Vector2f size);
	void Move(sf::Vector2f p_speed);
	void PaddleBounce(sf::Vector2f p_speed);
	
	~Ball();
	
	sf::Sprite * GetSprite();


};
