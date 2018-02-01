#include "Missil.h"

Missil::Missil() {
	missilTexture.loadFromFile("Resources/Textures/Misil2.png");
	missilSprite.setTexture(missilTexture);
	missilSprite.setRotation(-90);
	missilSprite.setScale(0.15f, 0.15f);
	
	isAlive = false;
}

void Missil::setPosition(float x, float y){
	missilSprite.setPosition(x, y);
}

void Missil::setDirectionX(float _movX){
	movX = _movX;
}

void Missil::setLive(bool a){
	isAlive = a;
}

bool Missil::getLive(){
	return isAlive;
}

void Missil::update (float elapsed) {
	missilSprite.move(movX * elapsed , elapsed * speed);
}

sf::FloatRect Missil::getBounds(){
	return missilSprite.getGlobalBounds();
}

sf::Vector2f Missil::getPosition(){
	return missilSprite.getPosition();
}

sf::Sprite Missil::getSprite(){
	return missilSprite;
}

void Missil::pause(){
	speed = 0;
}

void Missil::draw (sf::RenderWindow & w) {
	w.draw(missilSprite);
}

