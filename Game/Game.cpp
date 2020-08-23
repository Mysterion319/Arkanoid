#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Blocks.h"
#include "SpeedPowerUp.h"
#include "MultiBallPowerUp.h"
#include "EnlargePaddlePowerUp.h"
#include "Background.h"
using namespace std;









Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML Starter Template");



	
	m_background = new Background(sf::Vector2f(0, 0.f));

	m_paddle = new Paddle(sf::Vector2f(10.f, 10.f));

	
	m_ball = new Ball(sf::Vector2f(10.f, 10.f));
	m_speedpowerup = new SpeedPowerUp(sf::Vector2f(10.f, 10.f));

	m_EnlargePaddlePowerUp = new EnlargePaddlePowerUp(sf::Vector2f(10.f, 10.f));

	m_multiBallPowerUp = new MultiBallPowerUp(sf::Vector2f(10.f, 10.f));
	m_Extrball1 = new MultiBallPowerUp(sf::Vector2f(10.f, 10.f));
	m_Extrball2 = new MultiBallPowerUp(sf::Vector2f(10.f, 10.f));

	m_blocks = new Blocks();




	//Clock<> clock;

	//constexpr long long spawnRate = 3000;
	//while (true) {
	//	if (clock.getMilliseconds() >= spawnRate) {
	//		std::cout << "SPAWN\n";
	//		clock.reset();
	//	}
	//}






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
		m_paddle->ChangeMovementSpeed(10.f);
		m_paddle->setSpeedPowerUpTexture(0);
		specalOn = true;

		totalTime = 0.0f;


	}
	if (specalOn and totalTime > 5)
	{
		specalOn = false;
		totalTime = 0.0f;
		m_paddle->setSpeedPowerUpTexture(1);
	}

	m_paddle->DrawPoweredUpSprite()->setPosition(m_paddle->GetSprite()->getPosition().x, m_paddle->DrawPoweredUpSprite()->getPosition().y);



	


     // Multiball Powerup
	if (m_multiBallPowerUp->GetSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{


		m_multiBallPowerUp->GetSprite()->setPosition(1000, 1000);
		m_Extrball1 = new MultiBallPowerUp(sf::Vector2f(10.f, 10.f));
		m_Extrball2 = new MultiBallPowerUp(sf::Vector2f(10.f, 10.f));
	


	}

	if (m_Extrball1->GetExtraBallSprite()->getPosition().x < 0)
	{
		m_Extrball1->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
	}

	if (m_Extrball1->GetExtraBallSprite()->getPosition().y < 0)
	{
		m_Extrball1->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
	}

	if (m_Extrball1->GetExtraBallSprite()->getPosition().x > 640)
	{
		m_Extrball1->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
	}

	if (m_Extrball1->GetExtraBallSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{
		m_Extrball1->ChangeDirection(sf::Vector2f(1.0f, -1.0f));

	}

	//Extra Ball 1 intersect code.

	if (m_Extrball1->GetExtraBallSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{
		m_Extrball1->ChangeDirection(sf::Vector2f(1.0f, -1.0f));

	}
	//Extra Ball 2 intersect code.

	if (m_Extrball2->GetExtraBall2Sprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{
		m_Extrball2->ChangeDirection(sf::Vector2f(1.0f, -1.0f));

	}


	// Extra Ball 1 intersecting with the blocks code.
	for (int i = 0; i < m_blocks->getblocks()->size(); i++)
	{

		if (m_Extrball1->GetExtraBallSprite()->getGlobalBounds().intersects(m_blocks->getblocks()->at(i)->getGlobalBounds()))
		{

			if (m_Extrball1->GetExtraBallSprite()->getPosition().x < m_blocks->getblocks()->at(i)->getPosition().x - m_blocks->getblocks()->at(i)->getGlobalBounds().width)
			{
				m_Extrball1->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
			}
			else if (m_Extrball1->GetExtraBallSprite()->getPosition().x > m_blocks->getblocks()->at(i)->getPosition().x + m_blocks->getblocks()->at(i)->getGlobalBounds().width)
			{
				m_Extrball1->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
			}


			if (m_Extrball1->GetSprite()->getPosition().y < m_blocks->getblocks()->at(i)->getPosition().y - m_blocks->getblocks()->at(i)->getGlobalBounds().height)
			{
				m_Extrball1->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
			}
			else if (m_Extrball1->GetExtraBallSprite()->getPosition().y > m_blocks->getblocks()->at(i)->getPosition().y + m_blocks->getblocks()->at(i)->getGlobalBounds().height)
			{
				m_Extrball1->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
			}

			m_blocks->getblocks()->erase(m_blocks->getblocks()->begin() + i);

		}
	}



	// Extra Ball 2 intersecting with the blocks code.
	for (int i = 0; i < m_blocks->getblocks()->size(); i++)
	{

		if (m_Extrball2->GetExtraBall2Sprite()->getGlobalBounds().intersects(m_blocks->getblocks()->at(i)->getGlobalBounds()))
		{

			if (m_Extrball2->GetExtraBall2Sprite()->getPosition().x < m_blocks->getblocks()->at(i)->getPosition().x - m_blocks->getblocks()->at(i)->getGlobalBounds().width)
			{
				m_Extrball2->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
			}
			else if (m_Extrball2->GetExtraBall2Sprite()->getPosition().x > m_blocks->getblocks()->at(i)->getPosition().x + m_blocks->getblocks()->at(i)->getGlobalBounds().width)
			{
				m_Extrball2->ChangeDirection(sf::Vector2f(-1.0f, 1.0f));
			}


			if (m_Extrball2->GetSprite()->getPosition().y < m_blocks->getblocks()->at(i)->getPosition().y - m_blocks->getblocks()->at(i)->getGlobalBounds().height)
			{
				m_Extrball2->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
			}
			else if (m_Extrball2->GetExtraBall2Sprite()->getPosition().y > m_blocks->getblocks()->at(i)->getPosition().y + m_blocks->getblocks()->at(i)->getGlobalBounds().height)
			{
				m_Extrball2->ChangeDirection(sf::Vector2f(1.0f, -1.0f));
			}

			m_blocks->getblocks()->erase(m_blocks->getblocks()->begin() + i);

		}
	}




	//Enlarge paddle code.


	if (m_EnlargePaddlePowerUp->EnlargePaddlePowerUpSprite()->getGlobalBounds().intersects(m_paddle->GetSprite()->getGlobalBounds()))
	{

		m_paddle->GetSprite()->setScale(sf::Vector2f(1.5f,1.f));
		totalTime = 0.0f;
		m_EnlargePaddlePowerUp->EnlargePaddlePowerUpSprite()->setPosition(1000, 1000);
		EnlargeOn = true;
/*

		
		m_paddle->ChangeMovementSpeed(10.f);
		m_paddle->setEnlargedPowerUpTexture(0);
		

		
		

*/
	}
	if (EnlargeOn and totalTime > 5)
	{
		m_paddle->GetSprite()->setScale(sf::Vector2f(1.f, 1.f));
		totalTime = 0.0f;
		EnlargeOn = false;
		/*m_paddle->setEnlargedPowerUpTexture(1);*/
	}

	m_paddle->DrawPoweredUpSprite1()->setPosition(m_paddle->GetSprite()->getPosition().x, m_paddle->DrawPoweredUpSprite1()->getPosition().y);

	














}


void Game::draw() 
{
	
	window->draw(*m_background->GetSprite());
	window->draw(*m_paddle->GetSprite());
	window->draw(*m_paddle->DrawPoweredUpSprite());
	window->draw(*m_paddle->DrawPoweredUpSprite1());
	window->draw(*m_ball->GetSprite());
	/*window->draw(*m_Extrball1->GetExtraBallSprite());
	window->draw(*m_Extrball2->GetExtraBall2Sprite());
	window->draw(*m_multiBallPowerUp->GetSprite());*/
	window->draw(*m_speedpowerup->GetSprite());
	window->draw(*m_EnlargePaddlePowerUp->EnlargePaddlePowerUpSprite());
	

	
	
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

		fElapsedTime = timer.getElapsedTime().asSeconds();
		if (fElapsedTime > fFrameTime) {
			std::cout << totalTime << std::endl;
			totalTime += fFrameTime;
			timer.restart();
		}


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
		m_EnlargePaddlePowerUp->Move(sf::Vector2f(1.5f, 1.1f));
		m_multiBallPowerUp->Move(sf::Vector2f(1.5f, 1.1f));
		/*m_Extrball1->ExtraBallMove(sf::Vector2f(1.5f, 1.1f));
		m_Extrball2->ExtraBallMove(sf::Vector2f(1.5f, 1.1f));*/
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

