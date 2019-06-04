#include "Player.hpp"

void Player::move(int y, int x)
{
	y = (y > 532 && y < 968) ? y : (y < 532) ? 532 : 968;
	x = (x > 32 && x < 468) ? x : (x < 32) ? 32 : 468;

	setPosY(y);
	setPosX(x);
}
