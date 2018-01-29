#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "MenuScene.h"
using namespace sf;

int main(int argc, char *argv[]){
	BaseScene *scene = new MenuScene();
	Game &g = Game::create(sf::VideoMode(640, 480), scene, "Navecitas POO");
	g.run();
	
	return 0;
}

