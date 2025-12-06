#include "Point.hpp"
#include <iostream>

int main(void)
{
    // Triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    
    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A(0, 0), B(10, 0), C(5, 10)" << std::endl << std::endl;
    
    // Test point inside triangle
    Point p1(5.0f, 5.0f);
    std::cout << "Point (5, 5) is ";
    if (bsp(a, b, c, p1))
        std::cout << "INSIDE the triangle" << std::endl;
    else
        std::cout << "OUTSIDE the triangle" << std::endl;
    
    // Test point outside triangle
    Point p2(15.0f, 5.0f);
    std::cout << "Point (15, 5) is ";
    if (bsp(a, b, c, p2))
        std::cout << "INSIDE the triangle" << std::endl;
    else
        std::cout << "OUTSIDE the triangle" << std::endl;
    
    // Test point on vertex (should be false)
    Point p3(0.0f, 0.0f);
    std::cout << "Point (0, 0) [vertex] is ";
    if (bsp(a, b, c, p3))
        std::cout << "INSIDE the triangle" << std::endl;
    else
        std::cout << "OUTSIDE the triangle" << std::endl;
    
    // Test point on edge (should be false)
    Point p4(5.0f, 0.0f);
    std::cout << "Point (5, 0) [edge] is ";
    if (bsp(a, b, c, p4))
        std::cout << "INSIDE the triangle" << std::endl;
    else
        std::cout << "OUTSIDE the triangle" << std::endl;
    
    // More test points
    Point p5(5.0f, 2.0f);
    std::cout << "Point (5, 2) is ";
    if (bsp(a, b, c, p5))
        std::cout << "INSIDE the triangle" << std::endl;
    else
        std::cout << "OUTSIDE the triangle" << std::endl;
    
    Point p6(0.0f, 10.0f);
    std::cout << "Point (0, 10) is ";
    if (bsp(a, b, c, p6))
        std::cout << "INSIDE the triangle" << std::endl;
    else
        std::cout << "OUTSIDE the triangle" << std::endl;
    
    return 0;
}