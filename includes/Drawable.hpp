//Base class of all drawable objects

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>

enum eTexture //needed to find texture in container
{
	TABLE,
	PLAYER,
	ENEMY,
	PUCK,
	BACK,
	STRING
};

class Drawable
{
	int posy, posx;
	eTexture texture;
	std::string	name;

public:
	Drawable();
	Drawable(const int, const int, const eTexture);
	Drawable(const int, const int,
		const eTexture, const std::string);
	~Drawable() {}

	int getPosX() const { return posx; }
	int getPosY() const { return posy; }
	eTexture getTexture() const { return texture; }
	std::string getName() const { return name; }

	void setPosX(const int x) { posx = x; }
	void setPosY(const int y) { posy = y; }
	void setName(const std::string str) { name = str; }
	
};

#endif