
#include "..\include\Ship.h" 
#include <iostream>

//



Ship::Ship(sf::Vector2f size)
{



	m_ship = new sf::Sprite();
	sf::Texture* shipTexture;  shipTexture = new sf::Texture();
	
	if (!shipTexture->loadFromFile("Assests/Sprites/ship.png"))
	{

	}
	m_ship->setTexture(*shipTexture);
	m_ship->setOrigin(sf::Vector2f(m_ship->getPosition().x + -150, size.y - m_ship->getPosition().y + 5));
	m_ship->setPosition(sf::Vector2f(m_ship->getPosition().x, size.y - m_ship->getPosition().y));
	m_ship->setScale(0.1f, 0.1f);

	
}	


Ship::~Ship()
{
}

void Ship::Move(sf::Vector2f p_speed)
{

	m_ship->setPosition(m_ship->getPosition().x +  p_speed.x, m_ship->getPosition().y + p_speed.y );

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= accel;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += accel;
	}
	else
	{
		velocity.x *= decel;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= accel;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y += accel;
	}
	else
	{
		velocity.y *= decel;
	}*/

	//Make sure the ship isn't going too fast
	/*if (velocity.x < -maxspeed) velocity.x = -maxspeed;
	if (velocity.x > maxspeed) velocity.x = maxspeed;
	if (velocity.y < -maxspeed) velocity.y = -maxspeed;
	if (velocity.y > maxspeed) velocity.y = maxspeed;*/

	//collison 


	/*if (m_ship->getPosition().x > 360)
	{
		m_ship->setPosition(360, m_ship->getPosition().y);
	}
	if (m_ship->getPosition().x < -360)
	{
		m_ship->setPosition(-360, m_ship->getPosition().y);
	}
	if (m_ship->getPosition().y > 560)
	{
		m_ship->setPosition(m_ship->getPosition().x, 560);
	}
	if (m_ship->getPosition().y < 20)
	{
		m_ship->setPosition(m_ship->getPosition().x, 20);
	}
*/


}

sf::Sprite * Ship::GetSprite()
{
	return m_ship;
}