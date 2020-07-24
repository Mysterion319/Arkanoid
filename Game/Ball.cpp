#include "Ball.h"




Ball::Ball(sf::Vector2f size)
{
	float static const BallSetScaleX = 2.0f;
	float static const BallSetScaleY = 2.0f;
	float static const BallSetPositionX = 260.f;
	float static const BallSetPositionY = 260.f;
	m_ball = new sf::Sprite();




	if (!texture.loadFromFile("Assests/Sprites/Ball.png"))
	{

	}
	

	const sf::Texture* BallTexture = &texture;
	m_ball->setTexture(*BallTexture);
	m_ball->setPosition(BallSetPositionX, BallSetPositionY);
	m_ball->setScale(BallSetScaleX, BallSetScaleY);



}



Ball::~Ball()
{

	

}

sf::Sprite * Ball::GetSprite()
{
	return m_ball;
}