#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
public:
    double x;
    double y;

    Point2D();
    Point2D(double x, double y);

    static double distance(const Point2D &a, const Point2D &b);
    bool operator==(const Point2D &a) const;
    bool operator!=(const Point2D &a) const;
    Point2D operator-(const Point2D &p) const;
    Point2D operator*(const Point2D &p) const;
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
    double norm() const;
};

#endif