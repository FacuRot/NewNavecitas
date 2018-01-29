#ifndef ITEM_H
#define ITEM_H
#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
using namespace std;

class Item : public Entity {
private:
	float speed = 0.0f;
	
	sf::Texture itemTexture;
	sf::Sprite itemSprite;
	int textureTracker;
public:
	Item();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
	void changeTexture (string newTexture);
	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	void startMoving();
	void resetPos();
	void setTextureTracker(int a);
	int getTextureTracker();
};

#endif

