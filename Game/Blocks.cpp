#include "Blocks.h"
#include <array>
#include <iostream>
using std::array;


Blocks::Blocks()
{

	int m = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			blocks.at(m) = new sf::Sprite();
			m++;
		}


	blockTexture.loadFromFile("Assests/Sprites/block.png");
	

	int n = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{ 
			blocks.at(n)->setTexture(blockTexture);
			blocks.at(n)->setPosition(i * 55, j * 30);
			n++;
		}



}



Blocks::~Blocks()
{


}

array<sf::Sprite*, 100> Blocks::getblocks()
{
	return blocks;
}




