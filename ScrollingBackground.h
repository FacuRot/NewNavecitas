#ifndef SCROLLINGBACKGROUND_H
#define SCROLLINGBACKGROUND_H
#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class ScrollingBackground : public Entity {
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	
	float bgspeed = 100.0f;
	float bgY;
public:
	ScrollingBackground();
	void pause();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
};

#endif

