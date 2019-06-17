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

	int upBorder, downBorder;
	int leftBorder, rightBorder;
	int gateStart, gateEnd;

public:
	Puck();
	Puck(int, int);
	~Puck() {};

	void setDistance(const int);

	void initBorders(int, int);

	bool collision(Round *);
	void borders();
	void move();

};

#endif
