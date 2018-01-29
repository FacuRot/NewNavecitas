#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "BaseScene.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Missil.h"
#include "Item.h"
#include "Game.hpp"
#include "MenuScene.h"
#include "ScrollingBackground.h"
#include <SFML/System/Time.hpp>
#include "specialShoot.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace std;

class PlayScene : public BaseScene {
private:
	///musica y audio
	sf::SoundBuffer playerbuffer;
	sf::Sound playerGunFire;
	sf::SoundBuffer enemyBuffer;
	sf::Sound enemyGunFire;
	sf::SoundBuffer missilBuffer;
	sf::Sound launchMissil;
	sf::SoundBuffer itemBuffer;
	sf::Sound itemPickUp;
	sf::SoundBuffer explosionBuffer;
	sf::Sound explosionSound;
	sf::Music song;
	
	///textos del juego
	int score;
	sf::Font font;
	sf::Text txtScore;
	sf::Text txtGameOver;
	sf::Text txtNewRecord;
	
	///entidades del juego
	ScrollingBackground background;
	Player player;
	std::vector<Enemy> enemies;
	std::vector<Enemy2> specialEnemies;
	std::vector<Bullet> bullets;
	std::vector<Bullet> playerBullets;
	std::vector<Explosion> enemiesExplosions;
	std::vector<Missil> misils;
	Item item;
	
	///variables auxiliares
	int missilAmmo = 2;
	float addSpeed = 30.0f;
	sf::Time timeToNextItem;
	float delayItem;
public:
	PlayScene();
	
	void update (float elapsed);
	void gamePause();
	void processEvent(sf::RenderWindow &w, sf::Event &event);
	void draw (sf::RenderWindow & w);
};

#endif

