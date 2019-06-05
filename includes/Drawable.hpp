#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>

enum eTexture
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
	Drawable(int, int, eTexture);
	Drawable(int, int, eTexture, std::string);
	~Drawable() {}

	int getPosX() const {return posx;}
	int getPosY() const {return posy;}
	eTexture getTexture() const {return texture;}
	std::string getName() const { return name; }

	void setPosX(int x) {posx = x;}
	void setPosY(int y) {posy = y;}
	void setName(std::string str) {name = str;}
	
};

#endif