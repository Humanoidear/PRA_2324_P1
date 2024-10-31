#include "Circle.h"

Circle::Circle() : Shape() {
    center = Point2D(0, 0);
    radius = 1;
}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
    set_center(center);
    set_radius(radius);
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r <= 0) {
        throw std::invalid_argument("Invalid radius");
    }
    radius = r;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << "Circle: center = " << center << "; radius = " << radius << "; color = " << get_color() << std::endl;
}