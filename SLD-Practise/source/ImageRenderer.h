#pragma once
#include "Renderer.h"
#include "RenderManager.h"
#include <string>
#include <SDL3/SDL.h>
#include "Transform.h"

class ImageRenderer : public Renderer
{
public:

	ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize) : Renderer(transform, resourcePath)
	{
		RM->GetTexture(resourcePath);

		_sourceRect = SDL_FRect
		{
			sourceOffset.x,
			sourceOffset.y,
			sourceSize.x,
			sourceSize.y
		};

		_destinationRect = SDL_FRect
		{
			 transform->position.x,
			 transform->position.y,
			 transform->scale.x,
			 transform->scale.y
		};
	}
	void Update(float dt) override;
	void LoadTexture(std::string texturePath, SDL_Renderer* renderer);
	void Render() override;
};