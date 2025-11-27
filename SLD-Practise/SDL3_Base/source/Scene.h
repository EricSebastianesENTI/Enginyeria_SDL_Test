#pragma once
#include "Spawner.h"
#include "GameObject.h"
#include <vector>

class Scene
{
protected:
	std::vector<Object*> _objects;
	std::vector<Object*> _ui;

public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update();
	virtual void Render();
};