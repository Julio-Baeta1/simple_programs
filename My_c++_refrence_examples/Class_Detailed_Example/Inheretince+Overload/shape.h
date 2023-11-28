#ifndef Shape_H
#define Shape_H

#include <stdexcept>
#include <iostream>

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

        // Virtual declaration indicates that the function will be overridden in the derived class.
        // Since Shape is an abstract class this implementation doesn't matter but is included to illustarte for a none abstarct
        // base class.
        virtual void prettyPrint() { 
            std::cout<<"This is a shape with " << sides << " sides." << std::endl;
        }

        // Pure virtual function because of the = 0, it has no implementation in the base class and exists to be overridden in the
        // derived class.
        virtual double getArea() const = 0;
};

#endif