#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.hpp"
#include <vector>
using namespace std;


/***
 * Representa una escena del juego.
 * Para crear una nueva clase de escena, heredar de ésta clase
 * y redefinir el comportamiento de los métodos
 */ 
class BaseScene {
public:
	/// constructor
	BaseScene();
	
	/// función que será invocada para actualizar la escena
	virtual void update(float elapsed);
	
	virtual void processEvent(sf::RenderWindow &w, sf::Event &event);
	
	/// función que será invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);

	/// agrega un nuevo actor a la escena
	void add(Entity *e);
	
	/// eliminar un actor de la escena
	void remove(Entity *e);
	
private:
	vector<Entity *> entities;
	vector<Entity *> to_delete;
};

#endif

