#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

enum eTexture
{
	TABLE,
	PLAYER,
	ENEMY,
	PUCK
};

class Drawable
{
	int posy, posx;
	eTexture texture;

public:
	Drawable();
	Drawable(int, int, eTexture);
	~Drawable() {}

	int getPosX() const {return posx;}
	int getPosY() const {return posy;}
	eTexture getTexture() const {return texture;}

	void setPosX(int x) {posx = x;}
	void setPosY(int y) {posy = y;}
	
};

#endif