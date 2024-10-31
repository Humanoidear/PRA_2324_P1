#include "Shape.h"

Shape::Shape() {
    set_color("red");
}

Shape::Shape(std::string color) {
    set_color(color);
}

void Shape::set_color(std::string c) {
    if (color == "red" || color == "green" || color == "blue") {
        set_color(color);
    } else {
        std::invalid_argument("Invalid color");
    }
}

std::string Shape::get_color() const {
    return color;
}