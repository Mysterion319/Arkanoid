#include "Ball.h"




Ball::Ball(sf::Vector2f size)
{
	float static const BallSetScaleX = 2.0f;
	float static const BallSetScaleY = 2.0f;
	float static const BallSetPositionX = 300.f;
	float static const BallSetPositionY = 350.f;
	m_ball = new sf::Sprite();
	



	if (!texture.loadFromFile("Assests/Sprites/Ball.png"))
	{

	}
	

	const sf::Texture* BallTexture = &texture;
	m_ball->setTexture(*BallTexture);
	m_ball->setPosition(BallSetPositionX, BallSetPositionY);
	m_ball->setScale(BallSetScaleX, BallSetScaleY);



}

void Ball::Move(sf::Vector2f p_speed)
{
	float static const moveX = 0.0f;
	float static const moveY = 0.5f;
	//m_ball->setPosition(m_ball->getPosition().x + p_speed.x, m_ball->getPosition().y + p_speed.y);

	m_ball->move(moveX, moveY);
	
}

void Ball::PaddleBounce(sf::Vector2f p_speed)
{
	float static const PaddleBounceX = 0.0f;
	float static const PaddleBounceY = -0.5f;
	

	m_ball->move(PaddleBounceX, PaddleBounceY);

}
Ball::~Ball()
{

	

}

sf::Sprite * Ball::GetSprite()
{
	return m_ball;
}