#ifndef SPECIALSHOOT_H
#define SPECIALSHOOT_H
#include "Entity.hpp"
#include <vector>
#include "Missil.h"
using namespace std;

class specialShoot : public Entity{
private:
	vector<Missil> misils;
public:
	specialShoot(float x, float y);
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
};

#endif

