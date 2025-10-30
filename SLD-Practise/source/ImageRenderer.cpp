#include "ImageRenderer.h"
#include <SDL3_image/SDL_image.h>
#include <cassert>
#include "Vector2.h"

void ImageRenderer::Update()
{
	//...
}

void ImageRenderer::LoadTexture(std::string texturePath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, texturePath.c_str());
	assert(_texture);

	_sourceRect = { 0.f, 0.f, (float)_texture->w, (float)_texture->h };
}

void ImageRenderer::Render(SDL_Renderer* renderer)
{
	SDL_RenderTexture(renderer, _texture, &_sourceRect, &_destinationRect);
}