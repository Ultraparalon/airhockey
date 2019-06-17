#ifndef TABLE_HPP
#define TABLE_HPP

#include "Drawable.hpp"

class Table : public Drawable
{
	const int sizeY;
	const int sizeX;

public:
	Table();
	// Table(int, int);
	~Table();

	int getSizeY() const;
	int getSizeX() const;
	
};

#endif