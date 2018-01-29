#include "specialShoot.h"

specialShoot::specialShoot(float x, float y) {
	for (int i=0; i<3; i++){
		Missil* missil = new Missil(x, y);
		misils.push_back(*missil);
	}
	
	misils[0].setDirectionX(-200.0f);
	misils[1].setDirectionX(0.0f);
	misils[2].setDirectionX(200.0f);
}

void specialShoot::update (float elapsed) {
	misils[0].update(elapsed);
	misils[1].update(elapsed);
	misils[2].update(elapsed);
}

void specialShoot::draw (sf::RenderWindow & w) {
	misils[0].draw(w);
	misils[1].draw(w);
	misils[2].draw(w);
}

