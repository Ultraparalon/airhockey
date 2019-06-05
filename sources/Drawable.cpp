#include "Drawable.hpp"

Drawable::Drawable() : posy(0), posx(0), texture(TABLE), name("test") {}

Drawable::Drawable(const int y, const int x, const eTexture txr) :
	posy(y), posx(x), texture(txr), name("Name") {}

Drawable::Drawable(const int y, const int x,
	const eTexture txr, const std::string str) :
	posy(y), posx(x), texture(txr), name(str) {}
