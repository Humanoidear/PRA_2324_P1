#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = Point2D();
    }
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    vs = new Point2D[N_VERTICES];
    set_vertices(vertices);
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.get_color()) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Index out of range");
    }
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        set_color(r.get_color());
        set_vertices(r.vs);
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectangle: vertices = {";
    for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        out << r.vs[i];
        if (i < Rectangle::N_VERTICES - 1) {
            out << ", ";
        }
    }
    out << "}; color = " << r.get_color();
    return out;
}

bool Rectangle::check(Point2D* vertices) {
    // Check if the vertices form a rectangle
    // Check if the sides are perpendicular
    Point2D v1 = vertices[0] - vertices[1];
    Point2D v2 = vertices[1] - vertices[2];
    Point2D v3 = vertices[2] - vertices[3];
    Point2D v4 = vertices[3] - vertices[0];
    return true;
}

double Rectangle::area() const {
    Point2D v1 = vs[0] - vs[1];
    Point2D v2 = vs[1] - vs[2];
    return v1.norm() * v2.norm();
}

double Rectangle::perimeter() const {
    Point2D v1 = vs[0] - vs[1];
    Point2D v2 = vs[1] - vs[2];
    return 2 * (v1.norm() + v2.norm());
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << *this << std::endl;
}

Point2D& Rectangle::operator[](int index) {
    if (index < 0 || index >= N_VERTICES) {
        throw std::out_of_range("Index out of range");
    }
    return vs[index];
}