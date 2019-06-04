#ifndef TXTTEXTURE_HPP
#define TXTTEXTURE_HPP

#include <string>

class TxtTexture
{
	SDL_Texture * texture;

	TxtTexture() {};

public:
	TxtTexture(std::string);
	~TxtTexture();

	SDL_Texture * getTexture() { return texture; }
	
};

#endif
