#include <iostream>
#include <exception>
#include <SDL3/SDL.h>
#include "Game.h"

int main()
{
	Game game;

	try
	{
		game.Init();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what();
		game.Release();
		return -1;
	}

	while (game.isRunning())
	{
		game.HandleEvents();
		game.Update();
		game.Render();			
	}
	game.Release();
	return 0;
}