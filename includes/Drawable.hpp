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
	~Drawable();

	int getPosX() const;
	int getPosY() const;
	eTexture getTexture() const;
	std::string getName() const;

	void setPosX(const int x);
	void setPosY(const int y);
	void setPos(const int, const int);
	void setName(const std::string str);

	void moveY(const int);
	void moveX(const int);
	
};

#endif