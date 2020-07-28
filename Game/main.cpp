

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Blocks.h"
#include "Background.h"
#include <vector>

int main()
{

	







	sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid");//Create the window
	Paddle * m_paddle;
	Ball * m_ball;
	Blocks * m_blocks;
	Background * m_background;

	m_background = new Background(sf::Vector2f(0, 0.f));
	m_paddle = new Paddle(sf::Vector2f(10.f, 10.f));
	m_ball = new Ball(sf::Vector2f(10.f, 10.f));
	m_blocks = new Blocks();





	while (window.isOpen())
	{
		// handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			
		}

	

	
	
		

		window.clear();

		// draw SFML content
		window.draw(*m_background->GetSprite());
		

		window.draw(*m_paddle->GetSprite());
		window.draw(*m_ball->GetSprite());

		for (auto i : m_blocks->getblocks()) {
			window.draw(*i);
		}

		
			


		window.display();
	}

	return EXIT_SUCCESS;
}