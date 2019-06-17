#ifndef PUCK_HPP
#define PUCK_HPP

#include <cmath>
#include <cstdlib>
#include "Round.hpp"
#include <iostream>

class Puck : public Round
{
	int destY, destX;
	int distance;
	int power;

public:
	Puck();
	Puck(int, int);
	~Puck() {};

	bool	collision(Round *);
	void	borders();
	void	move();

};

#endif
