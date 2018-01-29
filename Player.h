#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <sstream>

class Player : public Entity {
private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	
	int rectx;
	int recty;
	
	float playerSpeed = 220.0f;
	sf::Vector2f playerDirection;
	
	int life = 150;
	sf::Font font;
	sf::Text text;
	std::stringstream convert;
	std::string lifestr;
	
	int score = 0;
	sf::Font font2;
	sf::Text scoreText;
	std::stringstream convertScore;
	std::string scorestr;
	
	void Up();
	void Down();
	void Left();
	void Right();
	
public:
	Player();
	sf::FloatRect getBounds();
	void getHit(int hit);
	sf::Vector2f getPosition();
	void pause();
	bool isDead();
	void heal();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
};

#endif

