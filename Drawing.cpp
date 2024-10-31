#include "Drawing.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing() {
    shapes = ListArray<Shape*>();
}

Drawing::~Drawing() {
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void Drawing::add_front(Shape* s) {
    shapes.prepend(s);
}

void Drawing::add_back(Shape* s) {
    shapes.append(s);
}

double Drawing::get_area_all_circles() {
    double area = 0;
    for (int i = 0; i < shapes.size(); i++) {
        Circle* c = dynamic_cast<Circle*>(shapes[i]);
        if (c != nullptr) {
            area += c->area();
        }
    }
    return area;
}

double Drawing::move_squares(double incX, double incY) {
    double perimeter = 0;
    for (int i = 0; i < shapes.size(); i++) {
        Square* s = dynamic_cast<Square*>(shapes[i]);
        if (s != nullptr) {
            s->translate(incX, incY);
            perimeter += s->perimeter();
        }
    }
    return perimeter;
}

void Drawing::print_all() {
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->print();
    }
}