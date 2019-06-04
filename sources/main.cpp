#include <iostream>
#include "Logic.hpp"
#include "MuliSdl.hpp"

void	wizard()
{
	Logic logic;
	MuliSdl sdl;

	while (!(sdl.getEvents() & (1 << 9)))
	{
		sdl.refresh();
		logic.process(sdl.getEvents(), sdl.getCoordinates());
		sdl.drawObj(logic.getDrawable());
		sdl.render();
		sdl.playSound(logic.getSound());
	}
}

int main()
{
	wizard();
	system("leaks airhockey");
	return 0;
}
