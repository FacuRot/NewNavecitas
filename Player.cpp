#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() {
	rectx = 0;
	recty = 0;
	
	playerTexture.loadFromFile("Resources/Textures/Entities.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(rectx, recty, 48, 63));
	playerSprite.setPosition(200.0f, 200.0f);
	
	//se toma la cantidad de vida y se convierte en texto que sigue a la nave
	font.loadFromFile("Resources/Fonts/Sansation.ttf");
	convert << life;
	lifestr = convert.str();
	text.setFont(font);
	text.setString(lifestr);
	text.setCharacterSize(21);
	text.setPosition(200.0f+9.0f, 200.0f+66.0f);
	
	font2.loadFromFile("Resources/Fonts/Sansation.ttf");
	convertScore << score;
	scorestr = convertScore.str();
	scoreText.setFont(font2);
	scoreText.setString(scorestr);
	scoreText.setCharacterSize(21);
	scoreText.setPosition(600, 20);
	
	playerDirection.x = 0.0f;
	playerDirection.y = 0.0f;
}

void Player::update (float elapsed) {
	rectx = 0;
	recty = 0;
	
	//se establece un rectangulo de textura para la nave
	playerSprite.setTextureRect(sf::IntRect(rectx, recty, 48, 63));
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		Up();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		Down();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		Left();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		Right();
	}
	
	playerSprite.move(playerDirection * playerSpeed * elapsed);
	text.move(playerDirection * playerSpeed * elapsed);
	
	playerDirection.x = 0.0f;
	playerDirection.y = 0.0f;
}

//funciones para mover la nave que ademas evita que se vaya por los extremos de la pantalla
void Player::Up(){
	playerDirection.y = -1;
	if (playerSprite.getPosition().y < 0){
		playerDirection.y = 0;
	}
}

void Player::Down(){
	playerDirection.y = 1;
	if (playerSprite.getPosition().y >= 480-64){
		playerDirection.y = 0;
	}
}

//si la nave se mueve hacia la izq. o derecha se cambia el rectangulo de textura
void Player::Left(){
	rectx = 48;
	playerSprite.setTextureRect(sf::IntRect(rectx, recty, 48, 63));
	playerDirection.x = -1;
	if (playerSprite.getPosition().x < 0){
		playerDirection.x = 0;
	}
	
}

void Player::Right(){
	rectx = 96;
	playerDirection.x = 1;
	if (playerSprite.getPosition().x >= 640-48){
		playerDirection.x = 0;
	}
	playerSprite.setTextureRect(sf::IntRect(rectx, recty, 48, 63));
}

sf::FloatRect Player::getBounds(){
	return playerSprite.getGlobalBounds();
}

void Player::getHit(int hit){
	if (life > 0){
		life -= hit;
	}
	
	if (life <= 0){
		life = 0;
		//se carga una textura transparente para que la nave desaparezca de la pantalla
		playerTexture.loadFromFile("Resources/Textures/fondo.png");
	}
	
	//se actualiza el string con la vida, el stringstream y el sf::Text para que cada vez que la nave
	//sea golpeada se muestre como la vida disminuye.
	//con cada golpe primero se pone un string vacio asi desaparece la cantidad de vida anterior 
	//y aparece la nueva sin superponerse una sobre la otra
	convert.str("");
	convert.clear();
	lifestr = convert.str();
	text.setString(lifestr);
	convert << life;
	lifestr = convert.str();
	text.setString(lifestr);
}

bool Player::isDead(){
	if (life <= 0){
		return true;
	}
	
	return false;
}

void Player::pause(){
	playerSpeed = 0;
}

sf::Vector2f Player::getPosition(){
	return playerSprite.getPosition();
}

void Player::draw (sf::RenderWindow & w) {
	w.draw(playerSprite);
	w.draw(text);
}

void Player::heal(){
	if (life > 0){
		life = 150;
		
		convert.str("");
		convert.clear();
		lifestr = convert.str();
		text.setString(lifestr);
		convert << life;
		lifestr = convert.str();
		text.setString(lifestr);
	}
}
