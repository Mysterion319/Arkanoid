#include "Paddle.h"



Paddle::Paddle(sf::Vector2f size)
{

	float static const PaddleSetScaleX = 1.3f;
	float static const PaddleSetScaleY = 1.3f;
	float static const PaddleSetPositionX = 250.f;
	float static const PaddleSetPositionY = 450.f;











	m_paddle = new sf::Sprite();// adding in new assigns it to the heap.

	if (!texture.loadFromFile("Assests/Sprites/Paddle.png"))
	{

	}
	const sf::Texture* paddleTexture = &texture;
	m_paddle->setTexture(*paddleTexture);
	m_paddle->setPosition(PaddleSetPositionX, PaddleSetPositionY);
	m_paddle->setScale(PaddleSetScaleX, PaddleSetScaleY);


	
}


Paddle::~Paddle()
{
}


sf::Sprite * Paddle::GetSprite()
{
	return m_paddle;
}
