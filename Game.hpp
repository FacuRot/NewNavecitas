#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BaseScene.hpp"
using namespace std;


/***
 * Clase para manejar un bucle de juego con distintas escenas
 */
class Game {
public:
	/// comenzar el bucle de juego
	void run();
	
	/// cambiar la escena actual por otra 
	void switchScene(BaseScene *scene);
	
	/// obtener la instancia de juego (singleton)
	static Game &getInstance();
	
	/// crear un juego especificando el modo de video y la escena inicial
	static Game &create(const sf::VideoMode &videoMode, BaseScene *scene, const string &name = "");

private:	
	sf::RenderWindow window;
	BaseScene *currentScene, *nextScene;
	sf::Clock clock;
	
	void processEvents(sf::Event &event);
	void update();
	void draw();
	static Game *instance;
	Game();
};

#endif

