#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "TestObject.h"
#include "InputManager.h"
void Game::Init()
{
	RM->Init();
	RM->LoadTexture("resources/xd.png");
	TestObject* test1 = new TestObject();
	_gameObjects.push_back(test1);
	TestObject* test2 = new TestObject();
	_gameObjects.push_back(test2);
	_isRunning = true;

}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		throw SDL_GetError();
	}
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
	if (IM->GetEvent(SDLK_S, DOWN))
	{
		
	}
}
void Game::Render()
{
	RM->ClearScreen();

	for (Object* go : _gameObjects)
	{
		go->Render();
	}
	RM->RendeScreen();
}
void Game::Realease()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
bool Game::isRunning() const
{
	return _isRunning;
}
void Game::CreateWindowAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer("Test", 512, 512, SDL_WINDOW_RESIZABLE, &_window, &_renderer))
		throw SDL_GetError();
}
