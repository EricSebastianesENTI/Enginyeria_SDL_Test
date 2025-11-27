#pragma once
#include <SDL3/SDL.h>
#include "Renderer.h"
#include "Transform.h"
#include "Rigidbody.h"

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Renderer* _renderer = nullptr;
	Transform* _transform;
	RigidBody* _physics;

public:
	Object()
	{ 
		_transform = new Transform();
		_physics = new RigidBody(_transform);
	}
	~Object()
	{
		delete _transform;
		_transform = nullptr;

		delete _renderer;
		_renderer = nullptr;

		delete _physics;
		_physics = nullptr;
	}
	virtual void Update()
	{ 
		if (_physics != nullptr)
		{
			_physics->Update(0.02f);
		}
		_renderer->Update(0.02f); 
	}

	virtual void Render() { _renderer->Render(); }
	Transform* GetTransform() { return _transform; } // De momento no hace nada
	RigidBody* GetRigidBody() { return _physics; } // De momento no hace nada
	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }

};