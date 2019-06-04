#ifndef PUCK_HPP
#define PUCK_HPP

#include <cmath>
#include <cstdlib>
#include "Drawable.hpp"
#include <iostream>

class Puck : public Drawable
{
	int destY, destX;
	int distance;
	int power;

public:
	Puck() : Drawable(500, 250, PUCK)
	{
		destY = destX = distance = power = 0;
	};
	Puck(int, int);
	virtual ~Puck() {};

	bool	collision(Drawable *);
	void	move();

};

#endif