#pragma once
/*#include "Vector2.h"
#include "Transform.h"
#include <SDL3/SDL.h>
#include <string>
#include "Renderer.h"*/

#include "Transform.h"
#include "Renderer.h"

class Object
{
private:
	 bool _isPendingDestroy = false;

protected:
	Renderer* _renderer;
	Transform* _transform;

public:
		 Object()
		 {
			 _transform = new Transform();
		 }
	
		 ~Object()
		 {
			delete _transform;
			_transform = nullptr;
		
			 delete _renderer;
			 _renderer = nullptr;
		 }
	
		 virtual void Update()
		 {
			 _renderer->Update(0.02f); // 50 FPS
		 }
	
		 virtual void Render()
		 {
			 _renderer->Render();
		 }
	
		 Transform * GetTransform() { return _transform; }
	 // De moment no fan res
		 bool IsPendingDestroy() const { return _isPendingDestroy; }
	 virtual void Destroy() { _isPendingDestroy = true; }
};