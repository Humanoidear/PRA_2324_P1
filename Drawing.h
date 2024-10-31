#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "ListArray.h"
#include "Shape.h"

class Drawing {
    private:
        ListArray<Shape*> shapes;

    public:
        Drawing();
        ~Drawing();
        void add_front(Shape* s);
        void add_back(int pos);
        double get_area_all_circles();
        double move_squares(double incX, double incY);
        void print_all();
};

#endif