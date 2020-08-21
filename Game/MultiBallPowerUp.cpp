#include "Paddle.h"
#include "SpeedPowerUp.h"

#include "MultiBallPowerUp.h"
MultiBallPowerUp::MultiBallPowerUp(sf::Vector2f size)
{




	moveX = 0.025f;
	moveY = 0.1f;
	ExtraBallMoveX = 0.05f;
	ExtraBallMoveY = 0.1f;

	m_multiBallPowerUp = new sf::Sprite();// adding in new assigns it to the heap.
	m_Extrball1 = new sf::Sprite();
	m_Extrball2 = new sf::Sprite();





	MultiBallPowerUpTexture = new sf::Texture();
	ExtraBall1Texture = new sf::Texture();
	ExtraBall2Texture = new sf::Texture();





	if (!MultiBallPowerUpTexture->loadFromFile("Assests/Sprites/MultiBallPowerUp.png"))
	{

	}


	m_multiBallPowerUp->setTexture(*MultiBallPowerUpTexture);

	m_multiBallPowerUp->setPosition(MultiBallPowerUpSetPositionX, MultiBallPowerUpSetPositionY);
	m_multiBallPowerUp->setScale(MultiBallPowerUpSetScaleX, MultiBallPowerUpSetScaleY);




	if (!ExtraBall1Texture->loadFromFile("Assests/Sprites/Ball.png"))
	{

	}

	m_Extrball1->setTexture(*ExtraBall1Texture);

	m_Extrball1->setPosition(ExtraBall1PowerUpSetPositionX, ExtraBall1PowerUpSetPositionY);
	m_Extrball1->setScale(ExtraBall1PowerUpSetScaleX, ExtraBall1PowerUpSetScaleY);




	if (!ExtraBall2Texture->loadFromFile("Assests/Sprites/Ball.png"))
	{

	}

	m_Extrball2->setTexture(*ExtraBall2Texture);

	m_Extrball2->setPosition(ExtraBall2PowerUpSetPositionX, ExtraBall2PowerUpSetPositionY);
	m_Extrball2->setScale(ExtraBall2PowerUpSetScaleX, ExtraBall2PowerUpSetScaleY);


}






void MultiBallPowerUp::Move(sf::Vector2f p_speed)
{

	m_multiBallPowerUp->move(moveX, moveY);

	



}

void MultiBallPowerUp::ExtraBallMove(sf::Vector2f p_speed)
{

	m_Extrball1->move(ExtraBallMoveX, ExtraBallMoveY);
	m_Extrball2->move(ExtraBallMoveX, ExtraBallMoveY);




}



void MultiBallPowerUp::ChangeDirection(sf::Vector2f p_change)
{
	ExtraBallMoveX = ExtraBallMoveX * p_change.x;
	ExtraBallMoveY = ExtraBallMoveY * p_change.y;

}








MultiBallPowerUp::~MultiBallPowerUp()
{
}



sf::Sprite * MultiBallPowerUp::GetSprite()
{
	return m_multiBallPowerUp;
}

sf::Sprite * MultiBallPowerUp::GetExtraBallSprite()
{
	return m_Extrball1;
}
sf::Sprite * MultiBallPowerUp::GetExtraBall2Sprite()
{
	return m_Extrball2;
}



