#include "Explosion.h"

Explosion::Explosion() {
	elapsedTime = 0;
	rectX = 0;
	rectY = 0;
	
	explosionTexture.loadFromFile("Resources/Textures/Explosion.png");
	explosionSprite.setTexture(explosionTexture);
	
	explosionSprite.setTextureRect(sf::IntRect(rectX, rectY, 250, 250));
	explosionSprite.setScale(0.6f, 0.6f);
	
	isAlive = false;
	finished = false;
}

bool Explosion::isFinished(){
	return finished;
}

void Explosion::setPosition(float posX, float posY){
	explosionSprite.setPosition(posX, posY);
	
	//cada vez que se posiciona la explocion es establece la variable como false
	//para que se rinicie la explocion cada vez que se pocisiona
	finished = false;
}

void Explosion::setLive(bool a){
	isAlive = a;
}

bool Explosion::getLive(){
	return isAlive;
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
			
			finished = true;
		}
	}
	
	explosionSprite.setTextureRect(sf::IntRect(rectX, rectY, 250, 250));
	elapsed = 0;
}

void Explosion::draw (sf::RenderWindow & w) {
	w.draw(explosionSprite);
}
