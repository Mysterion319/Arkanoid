#pragma once

#include <SFML/Graphics.hpp>
class Paddle;
class Background;
class Ball;
class Blocks;

class Game 
{
public:
	Game();
	~Game();

	void Loop();

private:
	Paddle * m_paddle;
	Background * m_background;
	Blocks * m_blocks;
	Ball * m_ball;
	sf::RenderWindow *window;
	

};



