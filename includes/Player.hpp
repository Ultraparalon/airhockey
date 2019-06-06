#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Drawable.hpp"

class Player : public Drawable
{
	int score;

public:
	Player() : Drawable(750, 250, PLAYER), score(0) {};
	~Player() {};

	int getScore() { return score;}

	void addPoint() { score++; }
	void move(int, int);
	
};

#endif
