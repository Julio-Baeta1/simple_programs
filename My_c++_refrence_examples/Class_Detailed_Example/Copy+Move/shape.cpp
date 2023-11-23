#include "shape.h"

void Shape::setNumSides(size_t s){
    if (s < 3)
        throw std::invalid_argument("sides must be greater than 2");
    sides = s;
}