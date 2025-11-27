#pragma once
#include <functional>
#include "ImageObject.h"
#include "InputManager.h"

class Button : public ImageObject
{
public:
	typedef std::function <void()> OnClick;

	Button(OnClick onClick) : ImageObject("resources/xd.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f))
	{
		_onClick = onClick;

		// Test
		_transform->position = Vector2(100.f, 100.f);
		_transform->scale = Vector2(1.f, 1.f);
		
		 _physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	virtual void Update() override
	{
		if (!_isHovered && _physics->CheckOverlappingPoint({ (float)IM->GetMouseX() , (float)IM->GetMouseY() }))
			OnHoverEnter();
		else if (_isHovered && !_physics->CheckOverlappingPoint({ (float)IM->GetMouseX() , (float)IM->GetMouseY() }))
			OnHoverExit();
		else if (_isHovered && IM->GetLeftClick())
			OnClicked();
		
			Object::Update();
	}

	void OnHoverEnter()
	{
		_transform->rotation = 90.f;
		_isHovered = true;
	}

	void OnHoverExit()
	{
		_transform->rotation = 0.f;
		_isHovered = false;
	}

	void OnClicked()
	{
		_onClick();
	}

	virtual void Render()// override
	{
		Object::Render();
	}


private:
	bool _isHovered = false;
	OnClick _onClick;
};