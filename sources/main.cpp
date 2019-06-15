#include "Logic.hpp"
#include "MuliSdl.hpp"
#include "EventKeeper.hpp"

void	wizard()
{
	Logic logic;
	MuliSdl sdl;
	EventKeeper events;

	while (!events.getExit())
	{
		sdl.refresh(events);
		logic.process(events);
		sdl.drawObj(logic.getDrawable());
		sdl.render();
		sdl.playSound(logic.getSound());
	}
}

int main()
{
	wizard();
	return 0;
}
