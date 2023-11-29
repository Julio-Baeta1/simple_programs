#include "circle.h"

Circle::Circle(const Circle& C){
    this->r = C.r;
    //Don't change sides as sides default =0 which is the same as circle
}

Circle::Circle(Circle && C){
    std::swap(this->r,C.r);
}

Circle & Circle::operator=(const Circle& C ){
    this->r = C.r;
    return *this;
}

Circle & Circle::operator=(Circle && C){
    std::swap(this->r, C.r);
    return *this;
}

ostream& operator<<(ostream& out, const Circle& C)
{
    out<< "circle with radius " << C.r << std::endl ;
    return out;
}


