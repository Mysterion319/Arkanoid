

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Paddle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid");//Create the window
	
	sf::Texture paddleTexture;
	paddleTexture.loadFromFile("Paddle.jpg");

	sf::Sprite paddle(paddleTexture);

	sf::Vector2u size = paddleTexture.getSize();
	paddle.setPosition(100,50);
	paddle.setScale(500, 500);



	while (window.isOpen())
	{
		// handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			
		}

	

	
		

		window.clear();

		// draw SFML content
		
		window.draw(paddle);
		window.display();
	}

	return EXIT_SUCCESS;
}