

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid");//Create the window
	



	
	while (window.isOpen())
	{
		// handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			
		}

	

	
		

		window.clear();

		// draw SFML content
		
	

		window.display();
	}

	return EXIT_SUCCESS;
}