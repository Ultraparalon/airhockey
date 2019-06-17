#include "Bot.hpp"

Bot::Bot() : Round(32, 250, 250, ENEMY), speed(3), score(0) {};
Bot::~Bot() {}

void Bot::initBorder(const int rhs)
{
	border = rhs / 2 - getRadius();
}

//Getters------------------------------------
int Bot::getScore()
{
	return score;
}

void Bot::addPoint()
{
	score++;
}

// bot is just pursuits puck
// with constant speed
void Bot::move(Drawable const * const rhs)
{
	for (int i = speed; i; i--)
	{
		if (rhs->getPosX() > this->getPosX())
		{
			this->moveX(1);
		}
		else
		{
			this->moveX(-1);
		}

		if (this->getPosY() <= border && rhs->getPosY() > this->getPosY()) // invisible barrier in the middle of the table
		{
			this->moveY(1);
		}
		else
		{
			this->moveY(-1);
		}
	}
}