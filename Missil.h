#ifndef MISSIL_H
#define MISSIL_H
#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
using namespace std;

class Missil:public Entity{
private:
	sf::Texture missilTexture;
	sf::Sprite missilSprite;
	
	bool isAlive;
	
	float movX;
	float speed = -200.0f;
public:
	Missil();
	void setPosition(float x, float y);
	sf::FloatRect getBounds();
	void update (float elapsed);
	void setDirectionX(float _movX);
	void setLive(bool a);
	bool getLive();
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	void pause();
	void draw (sf::RenderWindow & w);
};

#endif
