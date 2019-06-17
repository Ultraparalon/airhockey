#include "Drawable.hpp"

Drawable::Drawable() : posy(0), posx(0), texture(TABLE), name("test") {}

Drawable::Drawable(const int y, const int x, const eTexture txr) :
	posy(y), posx(x), texture(txr), name("Name") {}

Drawable::Drawable(const int y, const int x,
	const eTexture txr, const std::string str) :
	posy(y), posx(x), texture(txr), name(str) {}

Drawable::~Drawable() {}

//Getters---------------------------
int Drawable::getPosX() const
{
	return posx;
}

int Drawable::getPosY() const
{
	return posy;
}

eTexture Drawable::getTexture() const
{
	return texture;
}

std::string Drawable::getName() const
{
	return name;
}

//Setters-------------------
void Drawable::setPosY(const int y)
{
	posy = y;
}

void Drawable::setPosX(const int x)
{
	posx = x;
}

void Drawable::setName(const std::string str)
{
	name = str;
}
