#pragma once

#include <SFML/Graphics.hpp>
class Paddle;
class Background;
class Ball;
class Blocks;
class MultiBallPowerUp;
class SpeedPowerUp;
class EnlargePaddlePowerUp;
class Game 
{
public:
	Game();
	~Game();
	void GameScore();
	void PaddleLives();
	void Loop();



	void GameInput(sf::Event p_event);





private:
	float fFrameTime = 1.f / 60.f;
	float fElapsedTime = 0.f;
	float totalTime = 0;


	int Lives;
	int Score;
	bool specalOn; 
	bool EnlargeOn;



	sf::Clock timer;


	Paddle * m_paddle;
	Paddle * m_powerUpPaddle;
	Paddle * m_powerUpPaddle1;
	Background * m_background;
	Ball * m_ball;
	SpeedPowerUp * m_speedpowerup;
	EnlargePaddlePowerUp * m_EnlargePaddlePowerUp;
	MultiBallPowerUp * m_multiBallPowerUp;
	MultiBallPowerUp * m_Extrball1;
	MultiBallPowerUp * m_Extrball2;
	sf::RenderWindow *window;
	Blocks * m_blocks;


	sf::Text *m_gameScore;
	sf::Text *m_lifes;
	sf::Font font;//sets the font
	void draw();
};



