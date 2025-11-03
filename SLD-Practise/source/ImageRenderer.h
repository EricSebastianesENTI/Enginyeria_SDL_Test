#pragma once
#include "Renderer.h"
#include "RenderManager.h"
#include <string>
#include <SDL3/SDL.h>
#include "Transform.h"


class ImageRenderer : public Renderer
{
public:
	ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize);
		//: Renderer(transform, resourcePath)
	void Update(float dt) override;
	void LoadTexture(std::string texturePath, SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer) override;
};