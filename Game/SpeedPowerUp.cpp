#include "SpeedPowerUp.h"
#include <iostream>



SpeedPowerUp::SpeedPowerUp(sf::Vector2f size)
{


	float static const SpeedPowerUpSetScaleX = 0.05f;
	float static const SpeedPowerUpSetScaleY = 0.05f;
	float static const SpeedPowerUpeSetPositionX = 300.f;
	float static const SpeedPowerUpSetPositionY = 50.f;
	moveX = 0.025f;
	moveY = 0.035f;
	m_speedpowerup = new sf::Sprite();




	if (!texture.loadFromFile("Assests/Sprites/lightningPowerUP.png"))
	{

	}


	const sf::Texture* SpeedPowerUpTexture = &texture;
	m_speedpowerup->setTexture(*SpeedPowerUpTexture);
	m_speedpowerup->setPosition(SpeedPowerUpeSetPositionX, SpeedPowerUpSetPositionY);


	std::cout << m_speedpowerup->getPosition().x << m_speedpowerup->getPosition().y << std::endl;
	m_speedpowerup->setOrigin(m_speedpowerup->getGlobalBounds().width / 2, m_speedpowerup->getGlobalBounds().height / 2);

	std::cout << m_speedpowerup->getOrigin().x << m_speedpowerup->getOrigin().y << std::endl;



	m_speedpowerup->setScale(SpeedPowerUpSetScaleX, SpeedPowerUpSetScaleY);



}

void SpeedPowerUp::Move(sf::Vector2f p_speed)
{
	
		m_speedpowerup->move(moveX, moveY);





}



void SpeedPowerUp::ChangeDirection(sf::Vector2f p_change)
{
	moveX = moveX * p_change.x;
	moveY = moveY * p_change.y;

}



SpeedPowerUp::~SpeedPowerUp()
{



}

sf::Sprite * SpeedPowerUp::GetSprite()
{
	return m_speedpowerup;
}