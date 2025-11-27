#include <SDL3/SDL.h>
#include <iostream>
#include <exception>
#include "Game.h"
#include "RenderManager.h"
#include "TimeManager.h"
int main()
{
	RM->SayHi();	
	Game game;

	try
	{
		game.Init();		
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what();
		game.Realease();
		return -1;
	}
	while (game.isRunning())
	{
		TIME.Update();
		//std::cout << TIME.GetDeltaTime() << std::endl;
		if (TIME.ShouldUpdateGame())
		{
			game.HandleEvents();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
		}
	}
	game.Realease();
	
	return 0;
}