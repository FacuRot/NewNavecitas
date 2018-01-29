#include "MenuScene.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

MenuScene::MenuScene() {
	ifstream archi("puntajes.dat", ios::binary);
	archi.read(reinterpret_cast<char*>(&highScore), sizeof(int));
	
	menuSong.openFromFile("Resources/Music/MenuTheme.ogg");
	menuSong.setVolume(20);
	menuSong.play();
	
	if(!titleFont.loadFromFile("Resources/Fonts/Sansation.ttf")){
		std::cerr<<"ERROR: no se encontro la fuente "<<"Resources/Fonts/Sansation.ttf"<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::White);
	titleText.setString("Navecitas");
	titleText.setCharacterSize(120);
	// centra el texto
	titleText.setPosition(sf::Vector2f((640-titleText.getLocalBounds().width)/2.0, 0));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(sf::Color::White);
	stringstream ss;
	ss<<"HIGH SCORE: "<<highScore;
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(40);
	scoreText.setPosition(sf::Vector2f((640-scoreText.getLocalBounds().width)/2.0, 150));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(sf::Color::White);
	pressStartText.setString("Presione ENTER para comenzar");
	pressStartText.setCharacterSize(40);
	pressStartText.setPosition(sf::Vector2f((640-pressStartText.getLocalBounds().width)/2.0, 250));
}

void MenuScene::update (float elapsed) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		menuSong.stop();
		Game::getInstance().switchScene(new PlayScene());
	}
}

void MenuScene::draw (sf::RenderWindow & w) {
	BaseScene::draw(w);
	w.draw(titleText);
	w.draw(scoreText);
	w.draw(pressStartText);
}

