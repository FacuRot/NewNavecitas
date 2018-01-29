#include "ScrollingBackground.h"

ScrollingBackground::ScrollingBackground() {
	backgroundTexture.loadFromFile("Resources/Textures/Desert.png");
	backgroundTexture.setSmooth(false);
	backgroundTexture.setRepeated(true);
	
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0,0);
	
	bgY = 0;
	
	//se crea un textureRect del tamaño de la pantalla
	backgroundSprite.setTextureRect(sf::IntRect(0,bgY,640,480));
}

void ScrollingBackground::pause(){
	bgspeed = 0;
}

void ScrollingBackground::update (float elapsed) {
	//cuando la textura se va por el borde superior de la ventana se la vuelve a ubicar en el borde inferior
	if (bgY > 0){
		bgY -= bgspeed * elapsed;
	}else{
		bgY = 480;
	}
	
	backgroundSprite.setTextureRect(sf::IntRect(0, bgY, 640,480));
}

void ScrollingBackground::draw (sf::RenderWindow & w) {
	w.draw(backgroundSprite);
}

