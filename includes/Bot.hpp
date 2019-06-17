// Bot
// Just following puck

#ifndef BOT_HPP
#define BOT_HPP

#include "Round.hpp"

class Bot : public Round
{
	int speed;
	int score;

public:
	Bot();
	~Bot();
	
	int getScore();

	void addPoint();
	void move(Drawable const * const);
	
};

#endif
