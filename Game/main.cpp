

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Background.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid");//Create the window
	Paddle * m_paddle;
	Background * m_background;

	m_background = new Background(sf::Vector2f(0, 0.f));
	m_paddle = new Paddle(sf::Vector2f(-150.f, 300.f));
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
		window.display();
	}

	return EXIT_SUCCESS;
}