#ifndef ENEMY2_H
#define ENEMY2_H
#include "Entity.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Enemy2 : public Entity {
private:
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	
	float speedX = 200.0f;
	float speedY = 200.0f;
	
	sf::Time shootTime;   
	float delayShoot;
public:
	Enemy2();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
	sf::Vector2f getPosition();
	sf::FloatRect getBounds();
	void speedUp(float addSpeed);
	void pause();
	float getSpeed();
	bool fireEvent(float elapsed);
};

#endif

