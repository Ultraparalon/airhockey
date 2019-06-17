#include "Player.hpp"

Player::Player() : Round(32, 750, 250, PLAYER), score(0) {}
Player::~Player() {}

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
	y = (y >= 532 && y <= 968) ? y : (y < 532) ? 532 : 968;
	x = (x >= 32 && x <= 468) ? x : (x < 32) ? 32 : 468;

	setPosY(y);
	setPosX(x);
}
