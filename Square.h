#ifndef SQUARE_H
#define SQUARE_H

#include <ostream>
#include "Rectangle.h"

class Square : public Rectangle {
    private:
        static bool check(Point2D* vertices);

    public:
        Square();
        Square(std::string color, Point2D* vertices);
        Square(const Square &s);
        ~Square();
        friend std::ostream& operator<<(std::ostream &out, const Square &s);

        void set_vertices(Point2D* vertices) override;
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() override;
};

#endif