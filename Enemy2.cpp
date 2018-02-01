#include "Enemy2.h"
using namespace std;

Enemy2::Enemy2() {
	enemyTexture.loadFromFile("Resources/Textures/Avenger.png");
	enemySprite.setTexture(enemyTexture);
	
	enemySprite.rotate(180);
	
	enemySprite.setPosition(1+rand()%640,rand() % 400 - 500);
	
	delayShoot  = 0;
	shootTime = sf::seconds(3 + rand() % 8);
	
	isAlive = true;
}

void Enemy2::resetPosition(){
	enemySprite.setPosition(1+rand()%640,rand() % 400 - 500);
}

void Enemy2::setLive(bool a){
	isAlive = a;
}

bool Enemy2::getLive(){
	return isAlive;
}

void Enemy2::update (float elapsed) {
	if (enemySprite.getPosition().x < 0+60){
		speedX = 200.0f;
	}else if (enemySprite.getPosition().x > 640){
		speedX = -200.0f;
	}
	enemySprite.move(speedX * elapsed, speedY * elapsed);
	
	if (enemySprite.getPosition().y > 480 + 59){
		enemySprite.setPosition(1+rand()%640,rand() % 400 - 500);  
	}
}

void Enemy2::draw (sf::RenderWindow & w) {
	w.draw(enemySprite);
}

sf::FloatRect Enemy2::getBounds(){
	return enemySprite.getGlobalBounds();
}

bool Enemy2::fireEvent (float elapsed){
	delayShoot += elapsed;
	
	if (delayShoot >= shootTime.asSeconds()){
		while (delayShoot >= shootTime.asSeconds()){
			delayShoot -= shootTime.asSeconds();
		}
		return true;
	}
	
	return false;
}

sf::Vector2f Enemy2::getPosition(){
	return enemySprite.getPosition();
}

void Enemy2::speedUp(float addSpeed){
	speedX += addSpeed;
	speedY += addSpeed;
}

float Enemy2::getSpeed(){
	return speedX;
}

void Enemy2::pause(){
	speedX = 0;
	speedY = 0;
}
