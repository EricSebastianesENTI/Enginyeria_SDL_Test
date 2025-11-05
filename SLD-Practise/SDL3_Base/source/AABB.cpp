#include "AABB.h"

bool AABB::CheckOverLappingpoint(Vector2 point)
{
    bool isInsideX = point.x >= _topLeft.x && point.x <= _topLeft.x + _size.x;
    bool isInsideY = point.y >= _topLeft.y && point.y <= _topLeft.y + _size.y;

    return isInsideX && isInsideY;
}

bool AABB::CheckOverLappingAABB(const AABB* other)
{
    bool intersectionX = false;
    intersectionX |= _topLeft.x >= other->_topLeft.x && _topLeft.x <= other->_topLeft.x + other->_size.x;

    intersectionX |= other->_topLeft.x >= _topLeft.x && other->_topLeft.x <= _topLeft.x + _size.x;


    bool intersectionY = false;
    intersectionY |= _topLeft.y >= other->_topLeft.y && _topLeft.y <= other->_topLeft.y + other->_size.y;

    intersectionY |= other->_topLeft.y >= _topLeft.y && other->_topLeft.y <= _topLeft.y + _size.y;

    return intersectionX && intersectionY;
}