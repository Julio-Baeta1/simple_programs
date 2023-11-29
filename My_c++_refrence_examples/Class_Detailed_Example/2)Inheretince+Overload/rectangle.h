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

        //Override the pure virtual function in base class.
        double getArea() const override {return l*b;} 

        //Overload the operator < with our own implementation.
        //friend declaration allows a function that is not a member of the class to have access to all of its members.
        //This is often used when a function needs to access two classes
        friend bool operator<(const Rectangle& A, const Rectangle& B){
            return A.getArea() < B.getArea();
        }        

        //Overload the << operator, friend allows Rectangle member access to ostream object.
        friend ostream& operator<<(ostream& out, const Rectangle& R);
};

#endif