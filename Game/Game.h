#pragma once

#include <SFML/Graphics.hpp>
class Paddle;
class Background;
class Ball;
class Blocks;
class SpeedPowerUp;
class Game 
{
public:
	Game();
	~Game();
	void GameScore();
	void Loop();
	void GameInput(sf::Event p_event);
private:
	Paddle * m_paddle;
	Paddle * m_powerUpPaddle;
	Background * m_background;
	Ball * m_ball;
	SpeedPowerUp * m_speedpowerup;
	sf::RenderWindow *window;
	Blocks * m_blocks;
	sf::Text *m_gameScore;
	sf::Font font;//sets the font
	void draw();
};



