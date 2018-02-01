#include "Enemy.h"

using namespace std;

Enemy::Enemy() {
	enemyTexture.loadFromFile("Resources/Textures/Raptor.png");
	
	enemySprite.setTexture(enemyTexture);
	enemySprite.rotate(180);
	enemySprite.setScale(0.8f, 0.8f);
	
	//variables para manejar el tiempo de disparo de la nave
	delayShoot  = 0;
	shootTime = sf::seconds(3 + rand() % 11);
	
	enemySprite.setPosition(1+rand()%640,rand() % 400 - 500);
	
	isAlive = true;
}

bool Enemy::fireEvent(float elapsed){
	delayShoot += elapsed;
	
	if (delayShoot >= shootTime.asSeconds()){
		while (delayShoot >= shootTime.asSeconds()){
			delayShoot -= shootTime.asSeconds();
		}
		return true;
	}
	
	return false;
}

sf::Vector2f Enemy::getPosition(){
	return enemySprite.getPosition();
}

sf::FloatRect Enemy::getBounds(){
	return enemySprite.getGlobalBounds();
}

void Enemy::update (float elapsed) {
	enemySprite.move(0.0f, speed * elapsed);
	
	//una vez que se va por el borde inferior de la pantalla se vuelve a poner arriba
	if (enemySprite.getPosition().y > 480+51.2){
		enemySprite.setPosition(1+rand()%640,rand() % 400 - 500);  
	}
}

void Enemy::setLive(bool a){
	isAlive = a;
}

bool Enemy::getLive(){
	return isAlive;
}

void Enemy::pause(){
	speed = 0;
}

void Enemy::resetPosition(){
	enemySprite.setPosition(1+rand()%640,rand() % 400 - 500);
	isAlive = true;
}

void Enemy::draw (sf::RenderWindow & w) {
	w.draw(enemySprite);
}

