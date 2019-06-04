#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Drawable.hpp"

class Player : public Drawable
{
public:
	Player() : Drawable(750, 250, PLAYER) {};
	virtual ~Player() {};

	void move(int, int);
	
};

#endif