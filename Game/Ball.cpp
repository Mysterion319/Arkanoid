#include "Ball.h"
#include <iostream>



Ball::Ball(sf::Vector2f size)
{
	float static const BallSetScaleX = 2.0f;
	float static const BallSetScaleY = 2.0f;
	float static const BallSetPositionX = 300.f;
	float static const BallSetPositionY = 350.f;
	 moveX = 0.025f; 
	 moveY = 0.035f;
	m_ball = new sf::Sprite();
	



	if (!texture.loadFromFile("Assests/Sprites/Ball.png"))
	{

	}
	

	const sf::Texture* BallTexture = &texture;
	m_ball->setTexture(*BallTexture);
	m_ball->setPosition(BallSetPositionX, BallSetPositionY);

	
	std::cout << m_ball->getPosition().x << m_ball->getPosition().y <<  std::endl;
	m_ball->setOrigin(m_ball->getGlobalBounds().width / 2, m_ball->getGlobalBounds().height / 2);

	std::cout << m_ball->getOrigin().x << m_ball->getOrigin().y << std::endl;



	m_ball->setScale(BallSetScaleX, BallSetScaleY);



}

void Ball::Move(sf::Vector2f p_speed)
{
	
	m_ball->move(moveX, moveY);

	
	
}

void Ball::Rotate(float rotation)
{
	m_ball->rotate(rotation);
}


void Ball::ChangeDirection(sf::Vector2f p_change)
{
	moveX = moveX * p_change.x;
	moveY = moveY * p_change.y;

}



Ball::~Ball()
{

	

}

sf::Sprite * Ball::GetSprite()
{
	return m_ball;
}