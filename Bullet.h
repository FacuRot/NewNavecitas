#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.hpp"

class Bullet : public Entity{
private:
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	
	float posX;
	float posY;
	bool isAlive;
	
	float speed = 500.0f;
public:
	Bullet();
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	sf::FloatRect getBounds();
	void setLive(bool a);
	bool getLive();
	void setRotation(float degree);
	void setSpeed();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
	void pause();
};

#endif
