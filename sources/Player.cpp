#include "Player.hpp"

Player::Player() : Round(32, 750, 250, PLAYER), score(0) {}
Player::~Player() {}

void Player::initBorders(const int y, const int x)
{
	upBorder = y / 2 + getRadius();
	downBorder = y - getRadius();
	leftBorder = getRadius();
	rightBorder = x - getRadius();
}

//Getters--------------------
int Player::getScore() const
{
	return score;
}

//adds point to player score
void Player::addPoint()
{
	score++;
}

//moves player on board
void Player::move(int y, int x)
{
	// don't let move player through table centre and borders
	// and still moves in all axises even if cursor is not on table
	y = (y >= upBorder && y <= downBorder) ? y : (y < upBorder) ? upBorder : downBorder;
	x = (x >= leftBorder && x <= rightBorder) ? x : (x < leftBorder) ? leftBorder : rightBorder;

	setPosY(y);
	setPosX(x);
}
