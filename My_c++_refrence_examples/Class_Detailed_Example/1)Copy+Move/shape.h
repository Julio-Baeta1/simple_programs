#ifndef Shape_H
#define Shape_H

#include <stdexcept>
#include <iostream>

/*
    Instead of the explicitly defined functions it is possible provided the data members are primitive types (int,double, string) or
    objects for which defaults make sense (vector<string>) we can use deafults.

    Default copy constructor
        Shape(const Shape &S) = default;

    If we want to disallow moving/copying of the class we can use delete

    Disallow Move constructor
        Shape(Shape && S) = delete;

    *******************Note*****************************
    **  Deafults do not work for Pointer data members **
    ****************************************************
*/

class Shape{
    private:
        size_t sides;
    public:
        //Constructor
        //explicit ensures that Shape is not incorrectly cast as a size_t, e.g. Shape s1(3); size_t k{1}; s1 = k; throws an error
        explicit Shape(size_t s=0):sides{s} {std::cout << "Shape Constructor Called" << std::endl;}

        //Destructor
        ~Shape(){std::cout << "Invoking Shape Destructor" << std::endl;}

        //Copy Constructor
        Shape(const Shape &S):sides{S.sides} {std::cout << "Shape Copy Constructor Called" << std::endl;}

        //Copy Assignment
        Shape &operator= (const Shape &S){
            sides = S.sides;
            std::cout << "Shape Copy Assignment Called" << std::endl;
            return *this;
        }

        //Move Constructor
        Shape(Shape && S):sides{0}{
            std::cout << "Shape Move Constructor Called" << std::endl;
            std::swap(sides,S.sides);
        }

        //Move Assignment
        Shape & operator= (Shape && S){
            std::swap(sides,S.sides);
            std::cout << "Shape Move Assignment Called" << std::endl;
            return *this;
        }

        //Getter
        size_t getNumSides() const { return sides;}
        //Setter
        void setNumSides(size_t s) {sides = s;}
};

#endif