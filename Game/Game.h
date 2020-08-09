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
	void UpdateGame();
	void Loop();

private:
	Paddle * m_paddle;
	Background * m_background;
	Ball * m_ball;
	sf::RenderWindow *window;
	Blocks * m_blocks;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};



