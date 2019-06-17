#ifndef ROUND_HPP
#define ROUND_HPP

#include "Drawable.hpp"

class Round : public Drawable
{
	int radius;

public:
	Round();
	Round(int, int, int, eTexture);
	~Round();

	int getRadius() const;
	
};

#endif