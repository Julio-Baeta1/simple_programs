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

ostream& operator<<(ostream& out, const Rectangle& R)
{
    out<< "rectangle with " << R.sides << " sides, length= " << R.l << " and breadth = " << R.b << std::endl ;
    return out;
}


