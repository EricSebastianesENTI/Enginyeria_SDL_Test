#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

void Game::Init()
{
	 RM->Init();
	 RM->LoadTexture("resources/image.png ");
		 _isRunning = true;

		 TestObject* test1 = new TestObject();
		 _gameObjects.push_back(test1);
		  TestObject* test2 = new TestObject();
		  _gameObjects.push_back(test2);
}

void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}

void Game::Update()
{
	for (Object* go : _gameObjects)
	{
		go->Update();
	}

	if(IM->GetEvent(SDLK_S, KeyState::DOWN))
	{
		for (Object* go : _gameObjects)
		{
			go->GetTransform()->position.y += 0.05;
		}
	}
}

void Game::Render()
{
	 RM->ClearScreen();
	
	 for (Object* go : _gameObjects)
		 go->Render();
	
	 RM->RenderScreen();
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}


void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		throw SDL_GetError();
	}
}

void Game::CreateWindowAndRenderer()
{
	//Requiere: título, medidad de ancho-largo y flags relativos
	if (!SDL_CreateWindowAndRenderer("Test", 512, 512, SDL_WINDOW_RESIZABLE, &_window, &_renderer))
	{
		throw SDL_GetError();
	}
}