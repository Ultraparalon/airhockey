#include "Table.hpp"

Table::Table() : Drawable(500, 250, TABLE), sizeY(1000), sizeX(500) {}
Table::~Table() {}

//Getters-------------------------
int Table::getSizeY() const
{
	return sizeY;
}

int Table::getSizeX() const
{
	return sizeX;
}