#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "BaseScene.hpp"
#include "PlayScene.h"
#include <SFML/Graphics/Text.hpp>
#include "Game.hpp"
#include <SFML/Audio/Music.hpp>

class MenuScene : public BaseScene {
private:
	sf::Music menuSong;
	
	sf::Text titleText;
	sf::Text scoreText;
	sf::Text pressStartText;
	sf::Font titleFont;
public:
	int highScore = 0;
	MenuScene();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
};

#endif

