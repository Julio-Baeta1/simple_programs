#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
constexpr double pi = 3.14159265358979323846;
//#include <numbers> //Requires C++20

class Circle: public Shape
{
    private:
        double r;
    public:
        Circle(double i_r=0):r{i_r}{}; //default shape sides = 0 and a circle has inf sides which is not a size_t

        Circle(const Circle& C);
        Circle(Circle && C);
        Circle & operator=(const Circle & C);
        Circle & operator=(Circle && C);

        friend ostream& operator<<(ostream& out, const Circle& C); 

        //double getArea() const override {return std::numbers::pi*r*r;} //Requires C++20
        double getArea() const override {return pi*r*r;}

        friend bool operator<(const Circle& A, const Circle& B){
            return A.r < B.r;
        }     
};


#endif