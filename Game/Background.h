
#include <SFML/Graphics.hpp>


class Background
{

private:

	sf::Sprite * m_background;
	sf::Texture texture;

public:
	Background(sf::Vector2f size);

	sf::Sprite* GetSprite();


	~Background();
};
