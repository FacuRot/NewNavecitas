#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Bullet.h"
#include <vector>
using namespace std;

class Enemy : public Entity {
private:
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	
	float speed = 200.0f ;
	
	sf::Time shootTime;   
	float delayShoot;
	
public:
	Enemy();
	bool fireEvent(float elapsed);
	sf::Vector2f getPosition();
	sf::FloatRect getBounds();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
	void pause();
};

#endif

