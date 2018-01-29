#include "Missil.h"

Missil::Missil(float x, float y) {
	missilTexture.loadFromFile("Resources/Textures/Misil2.png");
	missilSprite.setTexture(missilTexture);
	missilSprite.setPosition(x, y);
	missilSprite.setRotation(-90);
	missilSprite.setScale(0.15f, 0.15f);
}

void Missil::setDirectionX(float _movX){
	movX = _movX;
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

