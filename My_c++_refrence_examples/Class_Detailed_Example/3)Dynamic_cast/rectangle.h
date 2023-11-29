#ifndef Rectangle_H
#define Rectangle_H

#include "shape.h"


class Rectangle : public Shape
{
    private: 
        double l,b;

    public:
        Rectangle(double i_l=0, double i_b=0): 
            l{i_l}, b{i_b}, Shape(4)
            {}

        Rectangle(const Rectangle& R);
        Rectangle(Rectangle&& R);

        Rectangle & operator=(const Rectangle& R);
        Rectangle & operator=(Rectangle&& R);

        friend ostream& operator<<(ostream& out, const Rectangle& R);   

        double getArea() const override {return l*b;} 

        friend bool operator<(const Rectangle& A, const Rectangle& B){
            return A.getArea() < B.getArea();
        }     
};

#endif