#include "Square.h"
#include <iostream>

Square::Square() : Rectangle() {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = Point2D();
    }
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices");
    }
}

Square::Square(const Square &s) : Rectangle(s.get_color(), s.vs) {}

Square::~Square() {
    delete[] vs;
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

std::ostream& operator<<(std::ostream &out, const Square &s) {
    out << "Square: vertices = {";
    for (int i = 0; i < Square::N_VERTICES; i++) {
        out << s.vs[i];
        if (i < Square::N_VERTICES - 1) {
            out << ", ";
        }
    }
    out << "}; color = " << s.get_color();
    return out;
}

double Square::area() const {
    return (vs[0] - vs[1]).norm() * (vs[1] - vs[2]).norm();
}

double Square::perimeter() const {
    return 4 * (vs[0] - vs[1]).norm();
}

void Square::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Square::print() {
    std::cout << *this << std::endl;
}