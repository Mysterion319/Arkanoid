#pragma once
#include <SFML/Graphics.hpp>
class MultiBallPowerUp
{


private:

	sf::Sprite * m_multiBallPowerUp;
	sf::Sprite * m_Extrball1;
	sf::Sprite * m_Extrball2;



	sf::Texture * MultiBallPowerUpTexture;
	sf::Texture * ExtraBall1Texture;
	sf::Texture * ExtraBall2Texture;




	float originalPosX, originalPosY;
	float moveX, moveY;
	float ExtraBallMoveX, ExtraBallMoveY;

	float  const MultiBallPowerUpSetScaleX = 2.0f;
	float  const MultiBallPowerUpSetScaleY = 2.0f;
	float  const MultiBallPowerUpSetPositionX = 300.f;
	float  const MultiBallPowerUpSetPositionY = 50.f;




	float  const ExtraBall1PowerUpSetScaleX = 2.0f;
	float  const ExtraBall1PowerUpSetScaleY = 2.0f;
	float  const ExtraBall1PowerUpSetPositionX = 5.f;
	float  const ExtraBall1PowerUpSetPositionY = 1.0f;


	float  const ExtraBall2PowerUpSetScaleX = 2.0f;
	float  const ExtraBall2PowerUpSetScaleY = 2.0f;
	float  const ExtraBall2PowerUpSetPositionX = 550.f;
	float  const ExtraBall2PowerUpSetPositionY = 1.0f;








public:
	MultiBallPowerUp(sf::Vector2f size);
	void Move(sf::Vector2f p_speed);
	void ExtraBallMove(sf::Vector2f p_speed);
	void ChangeDirection(sf::Vector2f p_change);




	sf::Sprite * GetSprite();

	sf::Sprite * GetExtraBallSprite();
	sf::Sprite * GetExtraBall2Sprite();
	~MultiBallPowerUp();




};






