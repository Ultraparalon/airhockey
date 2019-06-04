#include "Drawable.hpp"

Drawable::Drawable() : posy(0), posx(0), texture(TABLE) {}
Drawable::Drawable(int y, int x, eTexture txr) : posy(y), posx(x), texture(txr) {}
