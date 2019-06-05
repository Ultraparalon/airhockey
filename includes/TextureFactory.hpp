#ifndef TEXTUREFACTORY_HPP
#define TEXTUREFACTORY_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include "Drawable.hpp"
#include "Texture.hpp"

class TextureFactory
{
	SDL_Renderer *ren;

	SDL_Color color;

	TTF_Font * defFont;

	std::vector<SDL_Texture *> textures;

public:

	TextureFactory();
	~TextureFactory();

	void init(SDL_Renderer *);

	Texture * createTexture(Drawable *);
	Texture * createTexture(int);
	
};

#endif