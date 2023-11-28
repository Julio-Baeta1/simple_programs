#include "rectangle.h"

Rectangle::Rectangle(const Rectangle& R)
{
    this->b = R.b;
    this->l = R.l;
    this->sides = R.sides;
}

Rectangle::Rectangle(Rectangle&& R){
    std::swap(this->b,R.b);
    std::swap(this->l,R.l);
    std::swap(this->sides,R.sides);
}

Rectangle& Rectangle::operator=(const Rectangle& R){
    this->b = R.b;
    this->l = R.l;
    this->sides = R.sides;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle && R){
    std::swap(this->b,R.b);
    std::swap(this->l,R.l);
    std::swap(this->sides,R.sides);
    return *this;
}

void Rectangle::prettyPrint()
{
    std::cout << "Rectangle has " << this->getNumSides() << " sides with length= " << this->l << " and breadth = " << this->b << std::endl ;
}


