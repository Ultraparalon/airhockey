// Bot
// Just following puck

#ifndef BOT_HPP
#define BOT_HPP

#include "Drawable.hpp"

class Bot : public Drawable
{
	int speed;
	int score;

public:
	Bot() : Drawable(250, 250, ENEMY), speed(3), score(0) {};
	virtual ~Bot() {};
	
	int getScore() { return score;}

	void addPoint() { score++; }
	void move(Drawable const * const);
	
};

#endif