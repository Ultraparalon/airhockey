#include "Round.hpp"

Round::Round() : radius(0) {}

Round::Round(int r, int y, int x, eTexture t) :
					Drawable(y, x, t), radius(r) {}

Round::~Round() {}

//Getters---------------------
int Round::getRadius() const
{
	return radius;
}