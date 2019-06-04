#include "Drawable.hpp"

Drawable::Drawable() : posy(0), posx(0), texture(TABLE), name("test") {}
Drawable::Drawable(int y, int x, eTexture txr) :
	posy(y), posx(x), texture(txr), name("Name") {}
Drawable::Drawable(int y, int x, eTexture txr, std::string str) :
	posy(y), posx(x), texture(txr), name(str) {}
