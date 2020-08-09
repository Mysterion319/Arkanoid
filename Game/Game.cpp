#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Blocks.h"
#include "Background.h"


Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML Starter Template");

	m_background = new Background(sf::Vector2f(0, 0.f));

	m_paddle = new Paddle(sf::Vector2f(10.f, 10.f));
	m_ball = new Ball(sf::Vector2f(10.f, 10.f));
	m_blocks = new Blocks();
}


Game::~Game()
{
}



void Game::UpdateGame()
{



}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	



	
}


void Game::Loop()
{
	while (window->isOpen())
	{
		// handle events
		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:

				m_paddle->Move(event);
				break;

			default:
				break;
			}
		}

	
	
		if (m_ball->GetSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
		{
			m_ball->ChangeDirection(sf::Vector2f(1.0f,-1.0f));

		}


		for (int i = 0; i < m_blocks->getblocks()->size();i++)
		{

			if (m_ball->GetSprite()->getGlobalBounds().intersects(m_blocks->getblocks()->at(i)->getGlobalBounds()))
			{
				
				m_blocks->getblocks()->erase(m_blocks->getblocks()->begin() +i);

			}
		}

		
			
		m_ball->Move(sf::Vector2f(1.5f, 1.1f));
		window->clear();

		

	
		window->draw(*m_background->GetSprite());


		window->draw(*m_paddle->GetSprite());
		window->draw(*m_ball->GetSprite());


		for (int j = 0; j < m_blocks->getblocks()->size(); j++)
		{
			window->draw(*m_blocks->getblocks()->at(j));
		}


		window->display();
	}
}