#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Block;
class Game : public sf::Drawable
{
private:
	const float m_windowWidth;
	const float m_windowHeight;

	sf::Texture* t1;
	std::vector<Block*> m_block;
public:


	Game(float p_width, float p_height);
	
};
