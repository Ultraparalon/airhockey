#include "Bot.hpp"

void	Bot::move(Drawable * rhs)
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

		if (this->getPosY() <= 468 && rhs->getPosY() > this->getPosY())
		{
			this->setPosY(this->getPosY() + 1);
		}
		else
		{
			this->setPosY(this->getPosY() - 1);
		}
	}
}