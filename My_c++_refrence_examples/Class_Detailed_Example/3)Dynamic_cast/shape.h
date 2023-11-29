#ifndef Shape_H
#define Shape_H

#include <stdexcept>
#include <iostream>

using std::ostream;

//Shape is an abstarct class
class Shape{
    protected:

        size_t sides;

    public:

        explicit Shape(size_t s=0):sides{s} {}
        //Allow copy assignment as it is not an abstract class and we need it for dynamic casting.
        //Do not allow move constructor/assignment or copy constructor.
        Shape(const Shape &S) = delete;
        Shape(Shape && S) = delete;
        Shape &operator= (const Shape &S) = default;    
        Shape & operator= (Shape && S) = delete;    

        size_t getNumSides() const { return sides;}
        friend ostream& operator<<(ostream& out, const Shape& S){
            out << "is a shape with " << S.sides << std::endl;
            return out;
        }

        //Get area returns 0 unless overrided
        virtual double getArea() const{return 0;}

        //This function will call the derived class's version of getArea()
        double shapeArea(){
            return getArea();
        }

        //A dynamic_cast pointer of a shape dervied class can be used to determine if given shape's area is smaller than the this 
        //shape's area. If either object is only an instance of the Shape class or has 0 area return false.
        bool shapeFit(Shape* S){
            if (this->shapeArea() == 0 || S->shapeArea() == 0)
                return false;

            return this->shapeArea() > S->shapeArea();
        }

};

#endif