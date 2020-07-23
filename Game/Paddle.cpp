#include "Paddle.h"



Paddle::Paddle(sf::Vector2f size)
{
	m_paddle = new sf::Sprite();// adding in new assigns it to the heap.

	if (!texture.loadFromFile("Assests/Sprites/Paddle.jpg"))
	{

	}
	const sf::Texture* backgroundTexture = &texture;
	m_paddle->setTexture(*backgroundTexture);
	m_paddle->setPosition(sf::Vector2f(m_paddle->getPosition().x, size.y - m_paddle->getPosition().y));



	
}


Paddle::~Paddle()
{
}


sf::Sprite * Paddle::GetSprite()
{
	return m_paddle;
}
