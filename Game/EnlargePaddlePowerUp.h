#include <SFML/Graphics.hpp>
#pragma once


class EnlargePaddlePowerUp
{


private:

	sf::Sprite * m_EnlargePaddlePowerUp;

	sf::Texture texture;

	float originalPosX, originalPosY;
	float moveX, moveY;

	float  const EnlargePaddleSetScaleX = 2.3f;
	float  const EnlargePaddleSetScaleY = 2.3f;

	float  const EnlargePaddlePositionX = 300.f;
	float  const EnlargePaddlePositionY = 150.f;


	float   EnlargePaddleMoveLeft = -5.f;
	float   EnlargePaddleMoveRight = 5.f;


public:
	EnlargePaddlePowerUp(sf::Vector2f size);
	void Move(sf::Vector2f p_speed);

	void ChangeDirection(sf::Vector2f p_change);


	~EnlargePaddlePowerUp();

	sf::Sprite * EnlargePaddlePowerUpSprite();


};










