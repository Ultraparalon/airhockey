#include "Puck.hpp"

Puck::Puck() : Round(32, 500, 250, PUCK)
{
	destY = destX = distance = power = 0;
}

Puck::Puck(int y, int x) : Round(32, y, x, PUCK),
			destY(0), destX(0), distance(0), power(0) {}

//Setters-------------
void Puck::setDistance(const int i)
{
	distance = i;
}

// border initialisation
void Puck::initBorders(int y, int x)
{
	upBorder = getRadius();
	downBorder = y - getRadius();
	leftBorder = getRadius();
	rightBorder = x - getRadius();
	gateStart = x * 0.3;
	gateEnd = x * 0.7;
}

// search for destination of trajectory
static void	findDest(int x, int y, int sx, int sy, int & endX, int & endY, int distance)
{
	if (x == sx && y == sy)
	{
		// if somehow start and end is the same
		// just init with random values
		endY = rand();
		endX = rand();
		return ;
	}

	int shiftX = x - sx;
	int shiftY = y - sy;
	endX = sx;
	endY = sy;

	// builts line from base coordinates
	for (int h = distance; h > 0; h -= (abs(shiftX) + abs(shiftY)))
	{
		endX += shiftX;
		endY += shiftY;
	}
}

// detects collision
bool Puck::collision(Round * rhs)
{
	//init distance between rounds
	double r = sqrt(pow(this->getPosY() - rhs->getPosY(), 2)
		+ pow(this->getPosX() - rhs->getPosX(), 2));

	// colission check
	if ((r == 0 && this->getRadius() == rhs->getRadius()) ||
		(this->getRadius() + rhs->getRadius() >= r &&
			this->getRadius() + r >= rhs->getRadius() &&
			rhs->getRadius() + r >= this->getRadius()))
	{
		// udate power and distance
		power = this->getRadius() + rhs->getRadius() - r + 2;
		distance = (power * 256);

		//search destination
		findDest(this->getPosX(), this->getPosY(),
			rhs->getPosX(), rhs->getPosY(), destX, destY, distance);

		// move();
		return true;
	}
	return false;
}

// checks if puck close to borders
void Puck::borders()
{
	// up border check
	if (getPosY() < upBorder &&
		destY < upBorder &&
		(getPosX() < gateStart || getPosX() > gateEnd))
	{
		destY = upBorder + ((destY > 0) ? destY : abs(destY + getRadius()));
	}

	// down border check
	if (getPosY() > downBorder &&
		destY > downBorder &&
		(getPosX() < gateStart || getPosX() > gateEnd))
	{
		destY = downBorder - (destY - downBorder);
	}

	// left border check
	if (getPosX() < leftBorder &&
		destX < leftBorder)
	{
		destX = leftBorder + ((destX > 0) ? destX : abs(destX + getRadius()));
	}

	//right border check
	if (getPosX() > rightBorder &&
		destX > rightBorder)
	{
		destX = rightBorder - (destX - rightBorder);
	}
}

// move puck
void Puck::move()
{
	if (power && distance > 0)
	{
		// builds line to move
		// move speed is equals to power
		for (int i = power; i > 0 && (getPosY() != destY || getPosX() != destX);i--)
		{
			borders(); // border collision check

			int deltaX = abs(destX - getPosX());
			int deltaY = abs(destY - getPosY());
			int signX = getPosX() < destX ? 1 : -1;
			int signY = getPosY() < destY ? 1 : -1;
			int error = deltaX - deltaY;

			int error2 = error * 2;
			if (error2 > -deltaY)
			{
				error -= deltaY;
				moveX(signX);
			}
			if (error2 < deltaX)
			{
				error += deltaX;
				moveY(signY);
			}
		}
		distance -= power;
	}
}
