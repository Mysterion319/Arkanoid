

#include <SFML/Graphics.hpp>

class Paddle
{

private:

	sf::Sprite * m_paddle;

	sf::Sprite * m_powerUpPaddle;
	sf::Sprite * m_powerUpPaddle1;

	sf::Texture * paddletexture;
	sf::Texture * powerUptexture;
	sf::Texture * powerUptexture1;
	sf::Vector2f velocity;


	
	float  const PaddleSetScaleX = 1.f;
	float  const PaddleSetScaleY = 1.3f;
	float  const PaddleSetPositionX = 250.f;
	float  const PaddleSetPositionY = 450.f;
	float   PaddleMoveLeft = -5.f;
	float   PaddleMoveRight = 5.f;

	float  const EnlargedPaddleSetScaleX = 2.f;
	float const ogPaddleMoveLeft = -5.f;
	float  const ogPaddleMoveRight = 5.f;

public:
	Paddle(sf::Vector2f size);
	void Move(sf::Event event);

	void ChangeMovementSpeed(float p_powerupspeed);

	void setSpeedPowerUpTexture(int p_index);
	void setEnlargedPowerUpTexture(int p_index);
	sf::Sprite* GetSprite();
	sf::Sprite* DrawPoweredUpSprite();
	sf::Sprite* DrawPoweredUpSprite1();

	~Paddle();
};
