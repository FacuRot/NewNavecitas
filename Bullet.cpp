#include "Bullet.h"

Bullet::Bullet(float x, float y) {
	bulletTexture.loadFromFile("Resources/Textures/Bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.rotate(180);

	
	posX = x;
	posY = y;
	bulletSprite.setPosition(posX, posY);
}

sf::Vector2f Bullet::getPosition(){
	return bulletSprite.getPosition();
}

sf::FloatRect Bullet::getBounds(){
	return bulletSprite.getGlobalBounds();
}

void Bullet::setRotation(float degree){
	bulletSprite.setRotation(degree);
}

void Bullet::setSpeed(){
	speed = -1*speed;
}

void Bullet::update(float elapsed){
	bulletSprite.move(0, elapsed * speed);
	
}

void Bullet::draw(sf::RenderWindow &w){
	w.draw(bulletSprite);
}

void Bullet::pause(){
	speed = 0;
}
