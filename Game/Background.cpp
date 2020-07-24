#include "Background.h"


Background::Background(sf::Vector2f size)
{
	m_background = new sf::Sprite();// adding in new assigns it to the heap.

	if (!texture.loadFromFile("Assests/Sprites/Background.png"))
	{

	}
	const sf::Texture* backgroundTexture = &texture;
	m_background->setTexture(*backgroundTexture);
	m_background->setPosition(sf::Vector2f(m_background->getPosition().x, size.y - m_background->getPosition().y));
	m_background->setScale(4, 3);



}


Background::~Background()
{
}


sf::Sprite * Background::GetSprite()
{
	return m_background;
}
