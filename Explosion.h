#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

class Explosion : public Entity {
private:
	sf::Texture explosionTexture;
	sf::Sprite explosionSprite;
	
	float elapsedTime;
	sf::Clock timer;
	
	bool isAlive;
	bool finished;
	
	float rectX;
	float rectY;
public:
	Explosion();
	void setPosition(float posX, float posY);
	bool isFinished();
	void setLive(bool a);
	bool getLive();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
};

#endif
