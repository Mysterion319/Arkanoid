

#include <SFML/Graphics.hpp>

class Paddle
{

private:

	sf::Sprite * m_paddle;

	sf::Sprite * m_powerUpPaddle;
	sf::Texture * paddletexture;
	sf::Texture * powerUptexture;
	sf::Vector2f velocity;


	float  const PaddleSetScaleX = 1.f;
	float  const PaddleSetScaleY = 1.3f;
	float  const PaddleSetPositionX = 250.f;
	float  const PaddleSetPositionY = 450.f;
	float   PaddleMoveLeft = -10.f;
	float   PaddleMoveRight = 10.f;

	


public:
	Paddle(sf::Vector2f size);
	void Move(sf::Event event);

	void ChangeMovementSpeed(float p_powerupspeed);

	void setTexture(int p_index);
	sf::Sprite* GetSprite();
	sf::Sprite* DrawPoweredUpSprite();

	~Paddle();
};
