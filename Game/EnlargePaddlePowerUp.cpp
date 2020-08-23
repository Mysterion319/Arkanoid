#include "EnlargePaddlePowerUp.h"
#include <iostream>


EnlargePaddlePowerUp::EnlargePaddlePowerUp(sf::Vector2f size)
{


	
	moveX = 0.025f;
	moveY = 0.035f;
	m_EnlargePaddlePowerUp = new sf::Sprite();





	if (!texture.loadFromFile("Assests/Sprites/GrowPowerUP.png"))
	{

	}


	const sf::Texture* EnlargePaddlePowerUpTexture = &texture;
	
	m_EnlargePaddlePowerUp->setTexture(*EnlargePaddlePowerUpTexture);
	m_EnlargePaddlePowerUp->setPosition(EnlargePaddlePositionX, EnlargePaddlePositionY);


	std::cout << m_EnlargePaddlePowerUp->getPosition().x << m_EnlargePaddlePowerUp->getPosition().y << std::endl;
	m_EnlargePaddlePowerUp->setOrigin(m_EnlargePaddlePowerUp->getGlobalBounds().width / 2, m_EnlargePaddlePowerUp->getGlobalBounds().height / 2);

	std::cout << m_EnlargePaddlePowerUp->getOrigin().x << m_EnlargePaddlePowerUp->getOrigin().y << std::endl;



	m_EnlargePaddlePowerUp->setScale(EnlargePaddleSetScaleX, EnlargePaddleSetScaleY);



}

void EnlargePaddlePowerUp::Move(sf::Vector2f p_speed)
{

	m_EnlargePaddlePowerUp->move(moveX, moveY);





}



void EnlargePaddlePowerUp::ChangeDirection(sf::Vector2f p_change)
{
	moveX = moveX * p_change.x;
	moveY = moveY * p_change.y;

}



EnlargePaddlePowerUp::~EnlargePaddlePowerUp()
{



}

sf::Sprite * EnlargePaddlePowerUp::EnlargePaddlePowerUpSprite()
{
	return m_EnlargePaddlePowerUp;
}