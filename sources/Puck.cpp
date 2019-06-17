#include "Puck.hpp"

Puck::Puck() : Round(32, 500, 250, PUCK)
{
	destY = destX = distance = power = 0;
}

Puck::Puck(int y, int x) : Round(32, y, x, PUCK),
			destY(0), destX(0), distance(0), power(0) {}

// search for destination of trajectory
static void	findDest(int x, int y, int sx, int sy, int & endX, int & endY, int distance)
{
	if (x == sx && y == sy)
	{
		endY = rand() % 1000;
		endX = rand() % 500;
		return ;
	}

	int shiftX = x - sx;
	int shiftY = y - sy;
	endX = sx;
	endY = sy;
	for (int h = distance; h > 0; h -= (abs(shiftX) + abs(shiftY)))
	{
		endX += shiftX;
		endY += shiftY;
	}
}

// detects collision
bool	Puck::collision(Round * rhs)
{
	double r = sqrt(pow(getPosY() - rhs->getPosY(), 2)
		+ pow(getPosX() - rhs->getPosX(), 2));
	if ((r == 0 && this->getRadius() == rhs->getRadius()) ||
		(this->getRadius() + rhs->getRadius() >= r &&
			this->getRadius() + r >= rhs->getRadius() &&
			rhs->getRadius() + r >= this->getRadius()))
	{
		power = (this->getRadius() + rhs->getRadius() - r) + 2;
		distance += (power * 256);
		findDest(getPosX(), getPosY(),
			rhs->getPosX(), rhs->getPosY(), destX, destY, distance);

		move();
		return true;
	}
	return false;
}

// checks if puck close to borders
void	Puck::borders()
{
	if (getPosY() < 32 && (getPosX() < 160 || getPosX() > 340))
	{
		destY = 2000;
	}
	if (getPosY() > 968 && (getPosX() < 160 || getPosX() > 340))
	{
		destY = -1000;
	}
	if (getPosX() < 32)
	{
		destX = 1000;
		if (getPosX() < 16)
			setPosX(getPosX() + 32);
	}
	if (getPosX() > 468)
	{
		destX = -500;
		if (getPosX() > 484)
			setPosX(getPosX() - 32);
	}
}

// move puck
void	Puck::move()
{
	if (power)
	{
		int deltaX = abs(destX - getPosX());
		int deltaY = abs(destY - getPosY());
		int signX = getPosX() < destX ? 1 : -1;
		int signY = getPosY() < destY ? 1 : -1;
		int error = deltaX - deltaY;
		for (int i = power;
			i > 0 && (getPosY() != destY || getPosX() != destX); i--)
		{
			borders(); // need improvement
			
			int error2 = error * 2;
			if (error2 > -deltaY)
			{
				error -= deltaY;
				setPosX(getPosX() + signX);
			}
			if (error2 < deltaX)
			{
				error += deltaX;
				setPosY(getPosY() + signY);
			}			
		}
	}
}
