#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include "../ex02/Fixed.hpp"

class Point {
          private:
                    Fixed const x;
                    Fixed       y;
          public:
                    Point();
                    Point(float x_val, float y_val);
                    Point(const Point &other);
                    Point &operator=(const Point &other);
                    ~Point();

                    Fixed getX() const;
                    Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
