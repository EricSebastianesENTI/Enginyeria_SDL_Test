#include "Vector2.h"
#include <math.h>

void Vector2::Normalize()
{
		float length = sqrtf(x * x + y * y);
		x /= length;
		y /= length;
}