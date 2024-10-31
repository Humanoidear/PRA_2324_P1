#include "Point2D.h"
#include <cmath>

Point2D::Point2D() {
    x = 0;
    y = 0;
}

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool Point2D::operator==(const Point2D &a) const {
    return x == a.x && y == a.y;
}

bool Point2D::operator!=(const Point2D &a) const {
    return !(*this == a);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

Point2D Point2D::operator-(const Point2D &p) const {
    return Point2D(x - p.x, y - p.y);
}

Point2D Point2D::operator*(const Point2D &p) const {
    return Point2D(x * p.x, y * p.y);
}

double Point2D::norm() const {
    return std::sqrt(x * x + y * y);
}