#include "Explosion.h"

Explosion::Explosion(float posX, float posY) {
	elapsedTime = 0;
	rectX = 0;
	rectY = 0;
	
	explosionTexture.loadFromFile("Resources/Textures/Explosion.png");
	explosionSprite.setTexture(explosionTexture);
	
	explosionSprite.setTextureRect(sf::IntRect(rectX, rectY, 250, 250));
	explosionSprite.setPosition(posX, posY);
	explosionSprite.setScale(0.6f, 0.6f);
}

bool Explosion::isFinished(){
	return timer.getElapsedTime().asSeconds() >= (16 * 0.035f);
}

void Explosion::update (float elapsed) {
	elapsedTime += elapsed;
	
	if (elapsedTime > 0.035f){
		elapsedTime = 0.0f;
		
		if (rectX >= 1000){
			rectX = 0;
			rectY += 250;
		}else{
			rectX += 250;
		}
		
		if (rectY >= 1000){
			rectX = 0;
			rectY = 0;
		}
	}
	
	explosionSprite.setTextureRect(sf::IntRect(rectX, rectY, 250, 250));
	elapsed = 0;
}

void Explosion::draw (sf::RenderWindow & w) {
	w.draw(explosionSprite);
}

