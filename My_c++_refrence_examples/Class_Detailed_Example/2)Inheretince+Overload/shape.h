#ifndef Shape_H
#define Shape_H

#include <stdexcept>
#include <iostream>
#include <string>

using std::ostream, std::string;

//Shape is an abstarct class
class Shape{
    protected:

        size_t sides;
        // Only classes which inherit from Shape will have access to its constructor making it an abstarct class i.e. an instance
        // cannot exist unless as the base for a derived class.
        explicit Shape(size_t s=0):sides{s} {}

    public:
        //Do not allow any move/copy constructors/assignments
        Shape(const Shape &S) = delete;
        Shape(Shape && S) = delete;
        Shape &operator= (const Shape &S) = delete;    
        Shape & operator= (Shape && S) = delete;    

        size_t getNumSides() const { return sides;}

        // Pure virtual function because of the = 0, it has no implementation in the base class and exists to be overridden in the
        // derived class.
        virtual double getArea() const = 0;
};

#endif