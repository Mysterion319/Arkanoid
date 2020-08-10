#include "Blocks.h"
#include <vector>
#include <iostream>



Blocks::Blocks()
{
	 blocks = new vector< sf::Sprite*>;
	blocks->resize(100);

	int m = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			blocks->at(m) = new sf::Sprite();
		
			m++;
		}


	blockTexture.loadFromFile("Assests/Sprites/block.png");


	int n = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			blocks->at(n)->setTexture(blockTexture);
			blocks->at(n)->setPosition(i * 55, j * 30);
			blocks->at(n)->setOrigin(blocks->at(n)->getGlobalBounds().width / 2, blocks->at(n)->getGlobalBounds().height / 2);
			n++;
		}



}



Blocks::~Blocks()
{


}

vector<sf::Sprite*>* Blocks::getblocks()
{
	return blocks;
}

void Blocks::Rotate(float rotation)
{
		int n = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			blocks->at(n)->rotate(rotation);
			n++;
		}

	
}



