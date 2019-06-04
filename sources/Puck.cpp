#include "Puck.hpp"

static void	findDest(int x, int y, int sx, int sy, int & endX, int & endY)
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
	for (int h = 1000; h > 0; h -= (abs(shiftX) + abs(shiftY)))
	{
		endX += shiftX;
		endY += shiftY;
	}
}

Puck::Puck(int y, int x) : Drawable(y, x, PUCK),
			destY(0), destX(0), distance(0), power(0) {}

bool	Puck::collision(Drawable * rhs)
{
	double r = sqrt(pow(getPosY() - rhs->getPosY(), 2)
		+ pow(getPosX() - rhs->getPosX(), 2));
	if (r == 0 || (64 >= r && 32 + r >= 32 && 32 + r >= 32))
	{
		//make power formula
		power = 64 - r + 1;
		findDest(getPosX(), getPosY(),
			rhs->getPosX(), rhs->getPosY(), destX, destY);

		move();
		return true;
	}
	return false;
}

void	invertDest(int y, int x, int & destY, int & destX)
{
	if (y <= 32 && (x < 100 || x > 300))
	{
		destY = 2000;
		destX++;
	}
	if (y >= 968 && (x < 100 || x > 300))
	{
		destY = -1000;
		destX--;
	}
	if (x <= 32)
	{
		destX = 1000;
		destY++;
	}
	if (x >= 468)
	{
		destX = -500;
		destY--;
	}
}

void	Puck::move()
{
	if (power)
	{
		int deltaX = abs(destX - getPosX());
		int deltaY = abs(destY - getPosY());
		int signX = getPosX() < destX ? 1 : -1;
		int signY = getPosY() < destY ? 1 : -1;
		int error = deltaX - deltaY;
		int i;
		for (i = power; i && (getPosY() != destY || getPosX() != destX); i--)
		{
			invertDest(getPosY(), getPosX(), destY, destX);
			const int error2 = error * 2;
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
	//make movement formula
}
