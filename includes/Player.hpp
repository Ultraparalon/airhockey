#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Round.hpp"

class Player : public Round
{
	int score;

	int upBorder, downBorder;
	int leftBorder, rightBorder;

public:
	Player();
	~Player();

	void initBorders(const int, const int);

	int getScore() const;

	void addPoint();
	void move(int, int);
	
};

#endif
