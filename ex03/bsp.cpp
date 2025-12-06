#include "Point.hpp"

static Fixed cross(Fixed x1, Fixed y1, Fixed x2, Fixed y2)
{
    return x1 * y2 - y1 * x2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = cross(b.getX() - a.getX(), b.getY() - a.getY(),
                         point.getX() - a.getX(), point.getY() - a.getY());
    
    Fixed cross2 = cross(c.getX() - b.getX(), c.getY() - b.getY(),
                         point.getX() - b.getX(), point.getY() - b.getY());
    
    Fixed cross3 = cross(a.getX() - c.getX(), a.getY() - c.getY(),
                         point.getX() - c.getX(), point.getY() - c.getY());
    
    Fixed zero(0);
    
    if ((cross1 > zero && cross2 > zero && cross3 > zero) ||
        (cross1 < zero && cross2 < zero && cross3 < zero))
        return true;
    
    return false;
}
