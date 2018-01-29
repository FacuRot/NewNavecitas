#include "Item.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Item::Item() {
	srand(time(nullptr));
	
	itemTexture.loadFromFile("Resources/Textures/fondo.png");
	itemSprite.setTexture(itemTexture);
	itemSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
	itemSprite.setScale(0.8f, 0.8f);
	itemSprite.setPosition(1 + rand() % 640,rand() % 400 - 500);
}

void Item::update (float elapsed) {
	itemSprite.move(0, speed * elapsed);
	
	if (itemSprite.getPosition().y > 480){
		speed = 0;
		itemSprite.setPosition(1 + rand() % 640,rand() % 400 - 500);
		itemTexture.loadFromFile("Resources/Textures/fondo.png");
	}
}

void Item::draw (sf::RenderWindow & w) {
	w.draw(itemSprite);
}

sf::FloatRect Item::getBounds(){
	return itemSprite.getGlobalBounds();
}

void Item::changeTexture(string newTexture){
	itemTexture.loadFromFile(newTexture);
	itemSprite.setTexture(itemTexture);
}

sf::Vector2f Item::getPosition(){
	return itemSprite.getPosition();
}

void Item::startMoving(){
	//se le da una velocidad al azar entre 50 y 200
	speed = 50 + rand() % (201 - 50);
}

void Item::resetPos(){
	itemSprite.setPosition(1 + rand() % 640,rand() % 400 - 500);
	speed = 0;
}

void Item::setTextureTracker(int a){
	if (a == 1 || a==2){
		textureTracker = a;
	}
}

int Item::getTextureTracker(){
	return textureTracker;
}
