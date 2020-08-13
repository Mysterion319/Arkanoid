#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Blocks.h"
#include "SpeedPowerUp.h"

#include "Background.h"


Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML Starter Template");



	m_background = new Background(sf::Vector2f(0, 0.f));

	m_paddle = new Paddle(sf::Vector2f(10.f, 10.f));

	
	m_ball = new Ball(sf::Vector2f(10.f, 10.f));
	m_speedpowerup = new SpeedPowerUp(sf::Vector2f(10.f, 10.f));
	m_blocks = new Blocks();
}


Game::~Game()
{
}





void Game::GameInput(sf::Event p_event)
{
	//Ball going out of screen code.
	if (m_ball->GetSprite()->getPosition().x < 0)
	{
		m_ball->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
	}

	if (m_ball->GetSprite()->getPosition().y < 0)
	{
		m_ball->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
	}

	if (m_ball->GetSprite()->getPosition().x > 640)
	{
		m_ball->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
	}




	
	if (m_ball->GetSprite()->getPosition().y > 480)
	{
		m_ball->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
		m_ball->GetSprite()->setPosition(300,350);
	}



	// Ball Paddle intersect code.
	if (m_ball->GetSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{
		m_ball->ChangeDirection(sf::Vector2f(1.0f, -1.0f));

	}
	// Ball intersecting with the blocks code.
	for (int i = 0; i < m_blocks->getblocks()->size(); i++)
	{

		if (m_ball->GetSprite()->getGlobalBounds().intersects(m_blocks->getblocks()->at(i)->getGlobalBounds()))
		{

			if (m_ball->GetSprite()->getPosition().x < m_blocks->getblocks()->at(i)->getPosition().x - m_blocks->getblocks()->at(i)->getGlobalBounds().width)
			{
				m_ball->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
			}
			else if (m_ball->GetSprite()->getPosition().x > m_blocks->getblocks()->at(i)->getPosition().x + m_blocks->getblocks()->at(i)->getGlobalBounds().width)
			{
				m_ball->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
			}


			if (m_ball->GetSprite()->getPosition().y < m_blocks->getblocks()->at(i)->getPosition().y - m_blocks->getblocks()->at(i)->getGlobalBounds().height)
			{
				m_ball->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
			}
			else if (m_ball->GetSprite()->getPosition().y > m_blocks->getblocks()->at(i)->getPosition().y + m_blocks->getblocks()->at(i)->getGlobalBounds().height)
			{
				m_ball->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
			}

			m_blocks->getblocks()->erase(m_blocks->getblocks()->begin() + i);

		}
	}


	//Speed powerup 
	if (m_speedpowerup->GetSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{
		

		m_speedpowerup->GetSprite()->setPosition(1000, 1000);
		m_paddle->setTexture(0);
	
	
		

	}
	
	m_paddle->DrawPoweredUpSprite()->setPosition(m_paddle->GetSprite()->getPosition().x, m_paddle->DrawPoweredUpSprite()->getPosition().y);
	

	



}


void Game::draw() 
{
	
	window->draw(*m_background->GetSprite());
	window->draw(*m_paddle->GetSprite());
	window->draw(*m_paddle->DrawPoweredUpSprite());
	window->draw(*m_ball->GetSprite());
	window->draw(*m_speedpowerup->GetSprite());
	
}





void Game::GameScore()
{




	m_gameScore = new sf::Text();
	font.loadFromFile("Assests/Fonts/arial.ttf");
	m_gameScore->setCharacterSize(30);
	m_gameScore->setStyle(sf::Text::Bold);
	m_gameScore->setFont(font);
	m_gameScore->setPosition(250, 1);
	m_gameScore->setFillColor(sf::Color::White);


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
			case sf::Event::KeyPressed:

				m_paddle->Move(event);
				//m_blocks->Rotate(30.f);
				break;
	
			default:
				break;
			}
		}


		m_ball->Move(sf::Vector2f(1.5f, 1.1f));
		m_speedpowerup->Move(sf::Vector2f(1.5f, 1.1f));
		window->clear();

		draw();
		GameScore();
		

		for (int j = 0; j < m_blocks->getblocks()->size(); j++)
		{
			window->draw(*m_blocks->getblocks()->at(j));
		}



	
		GameInput(event);
		
		window->display();
	}
}

