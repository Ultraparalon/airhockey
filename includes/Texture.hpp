#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL.h>

class Texture
{
	SDL_Texture *texture;
	SDL_Rect rect;

	Texture();

public:
	Texture(SDL_Texture * lhs, SDL_Rect rhs) : texture(lhs), rect(rhs) {};
	~Texture() {};

	SDL_Texture * getTexture() const { return texture; }
	SDL_Rect * getRect() { return &rect; }
	
};

#endif