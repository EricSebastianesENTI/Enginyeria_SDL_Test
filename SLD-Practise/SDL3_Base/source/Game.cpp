#include "Game.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include <cassert>
void Game::Init()
{
	RM->Init();

	// Aquí la càrrega de tots els recursos del joc
	RM->LoadTexture("resources/xd.png");
	RM->LoadFont("resources/fonts/hyperspace.ttf");
	
	// Aquí la càrrega de totes les escenes
	assert(SM.AddScene("Gameplay", new Gameplay()));
	assert(SM.InitFirstScene("Gameplay"));

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
	SM.UpdateCurrentScene();
	if (IM->GetEvent(SDLK_S, DOWN))
	{
		
	}
}
void Game::Render()
{
	RM->ClearScreen();

	SM.GetCurrentScene()->Render();

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
