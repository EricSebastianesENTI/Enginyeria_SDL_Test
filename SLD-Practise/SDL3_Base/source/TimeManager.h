#pragma once
#include "SDL3/SDL.h"
#include <math.h>
#define TIME TimeManager::Instance()
class TimeManager
{
 private:
	 //Time control
	 float _deltaTime = 0.0f;
	 float _elapsedTime = 0.0f;
	 float _previousElapsedTime;

	 //FPS Control
	 const int _FPS = 60;
	 float _frameTime;

	TimeManager()
	{
		_deltaTime = 0.0f;
		_elapsedTime = 0.0f;
		_previousElapsedTime = (double)SDL_GetTicks() / 1000.0;

		_frameTime = 1.0f / (float)_FPS;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager& t) = delete;
	TimeManager& operator =(const TimeManager& t) = delete;

 public:
	static TimeManager& Instance()
	{
		static TimeManager instance;
		return instance;
	}

	float GetDeltaTime() { return _deltaTime; }
	float GetELapsedTime() { return _elapsedTime; }

	bool ShouldUpdateGame() { return _deltaTime >= _frameTime; }

	void ResetDeltaTime()
	{
		_deltaTime -= floor(_deltaTime / _frameTime) * _frameTime;
	}

	void Update()
	{
		_elapsedTime = (double)SDL_GetTicks() / 1000.0;
		_deltaTime += _elapsedTime - _previousElapsedTime;
		_previousElapsedTime = _elapsedTime;
	}
};