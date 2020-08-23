#include "Paddle.h"
#include "SpeedPowerUp.h"


Paddle::Paddle(sf::Vector2f size)
{

	




	//Normal paddle
	m_paddle = new sf::Sprite();// adding in new assigns it to the heap.
	m_powerUpPaddle = new sf::Sprite();
	m_powerUpPaddle1 = new sf::Sprite();
	paddletexture = new sf::Texture();
	powerUptexture = new sf::Texture();
	powerUptexture1 = new sf::Texture();
	if (!paddletexture->loadFromFile("Assests/Sprites/Paddle.png"))
	{

	}

	
	 //sf::Texture* paddleTexture = &paddletexture;
	
	m_paddle->setTexture(*paddletexture);

	m_paddle->setPosition(PaddleSetPositionX, PaddleSetPositionY);
	m_paddle->setScale(PaddleSetScaleX, PaddleSetScaleY);
	
	//Power up paddle
	if (!powerUptexture->loadFromFile("Assests/Sprites/PowerUpPaddle.png"))
	{

	}
	
	m_powerUpPaddle->setTexture(*powerUptexture);

	m_powerUpPaddle->setPosition(1000, 1000);
	m_powerUpPaddle->setScale(PaddleSetScaleX, PaddleSetScaleY);

	
	



	m_powerUpPaddle1->setScale(EnlargedPaddleSetScaleX, PaddleSetScaleY);



	//m_paddle->setScale(EnlargedPaddleSetScaleX, PaddleSetScaleY);





}


	






void Paddle::Move(sf::Event event)
{
	if (sf::Keyboard::Key::Left == event.key.code)
	{
		m_paddle->move(PaddleMoveLeft,0);
	}
	else if (sf::Keyboard::Key::Right == event.key.code)
	{
		m_paddle->move(PaddleMoveRight,0);
	}
	
}


void Paddle::ChangeMovementSpeed(float p_powerupspeed)
{

	PaddleMoveLeft -= p_powerupspeed;
	PaddleMoveRight += p_powerupspeed;
	

}





Paddle::~Paddle()
{
}


void Paddle::setSpeedPowerUpTexture(int p_index)
{
	if (p_index == 0)
	{
		
		m_powerUpPaddle->setPosition(m_paddle->getPosition().x -77, m_paddle->getPosition().y - 77);
	
		
	}

	else if (p_index == 1)
	{
		m_powerUpPaddle->setPosition(1000,1000);
		m_paddle->setTexture(*paddletexture);
		PaddleMoveLeft = ogPaddleMoveLeft;
		PaddleMoveRight = ogPaddleMoveRight;
	}
	

	
	
	
}


void Paddle::setEnlargedPowerUpTexture(int p_index)
{
	if (p_index == 0)
	{

		m_powerUpPaddle1->setPosition(m_paddle->getPosition().x, m_paddle->getPosition().y - 77);


	}

	else if (p_index == 1)
	{
		m_powerUpPaddle1->setPosition(1000, 1000);
		m_paddle->setTexture(*paddletexture);
		PaddleMoveLeft = ogPaddleMoveLeft;
		PaddleMoveRight = ogPaddleMoveRight;
	}



}



sf::Sprite * Paddle::GetSprite()
{
	return m_paddle;
}



sf::Sprite * Paddle::DrawPoweredUpSprite()
{
	return m_powerUpPaddle;
}



sf::Sprite * Paddle::DrawPoweredUpSprite1()
{
	return m_powerUpPaddle1;
}
