#include "ImageRenderer.h"
#include <SDL3_image/SDL_image.h>
#include <cassert>
#include "Vector2.h"

ImageRenderer::ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize)
	: Renderer(transform, resourcePath)
	{
		 RM->GetTexture(resourcePath);
		
			 _sourceRect = SDL_FRect
			 {
			 sourceOffset.x,
				 sourceOffset.y,
				 sourceSize.x,
				 sourceSize.y
			 };
		
			 _destRect = SDL_FRect
	 {
			 transform->position.x,
				 transform->position.y,
				 transform->scale.x,
				 transform->scale.y
	 };
}

virtual void ImageRenderer::Update(float dt) override
{
		 {
		 Vector2 offset = (Vector2(-_transform->size.x, -_transform->size.y) / 2.0f) * _transform ->
			scale;
		
			 _destRect.x = _transform->position.x + offset.x;
		 _destRect.y = _transform->position.y + offset.y;
		
			 _destRect.w = _transform->size.x * _transform - > scale.x;
		 _destRect.h = _transform->size.y * _transform - > scale.y;
		 }
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