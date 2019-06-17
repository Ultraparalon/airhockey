#include "Bot.hpp"

Bot::Bot() : Round(32, 250, 250, ENEMY), speed(3), score(0) {};
Bot::~Bot() {}

//Getters------------------------------------
int Bot::getScore()
{
	return score;
}

void Bot::addPoint()
{
	score++;
}

void Bot::move(Drawable const * const rhs)
{
	for (int i = speed; i; i--)
	{
		if (rhs->getPosX() > this->getPosX())
		{
			this->setPosX(this->getPosX() + 1);
		}
		else
		{
			this->setPosX(this->getPosX() - 1);
		}

		if (this->getPosY() <= 448 && rhs->getPosY() > this->getPosY()) // invisible barrier in the middle of the table
		{
			this->setPosY(this->getPosY() + 1);
		}
		else
		{
			this->setPosY(this->getPosY() - 1);
		}
	}
}