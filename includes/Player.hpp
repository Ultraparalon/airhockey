#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Round.hpp"

class Player : public Round
{
	int score;

public:
	Player();
	~Player();

	int getScore() const;

	void addPoint();
	void move(int, int);
	
};

#endif
