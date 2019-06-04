#include "Puck.hpp"

static void	findDest(int x, int y, int sx, int sy, int & endX, int & endY)
{
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

void	Puck::collision(Drawable * rhs)
{
	double r = sqrt(pow(getPosY() - rhs->getPosY(), 2)
		+ pow(getPosX() - rhs->getPosX(), 2));
	if (r == 0 || (64 >= r && 32 + r >= 32 && 32 + r >= 32))
	{
		//make power formula
		// std::cout << r << std::endl;
		power = 64 - r;
		findDest(rhs->getPosX(), rhs->getPosY(),
			getPosX(), getPosY(), destX, destY);

		// setPosY(rand() % 500 + 500);
		// setPosX(rand() % 500);
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
