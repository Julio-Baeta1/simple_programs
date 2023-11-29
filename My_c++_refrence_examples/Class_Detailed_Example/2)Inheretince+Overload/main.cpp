#include <iostream>
#include <memory>
#include "shape.h"
#include "rectangle.h"

using std::cout, std::endl, std::make_unique; 

int main()
{
    Rectangle A(4.0,2.0);
    cout <<"Shape A is a " << A << "The area of A = " << A.getArea() << endl << endl;

    Rectangle A1(A);
    cout << "copy constructor A1(A)" << endl;
    cout <<"Shape A1 is a " << A1 << "The area of A1 = " << A1.getArea() << endl << endl;

    Rectangle B(std::move(A1));
    cout << "move constructor B(A)" << endl << "B:" << endl;
    cout <<"Shape B is a " << B << "The area of B = " << B.getArea() << endl;
    cout <<"Shape A1 is a " << A1 << "The area of A1 = " << A1.getArea() << endl << endl;

    cout << "Copy assignment A1 = A" << endl;
    A1 = A;
    cout <<"Shape A1 is a " << A1 << "The area of A1 = " << A1.getArea() << endl << endl;

    cout << "Move Assigment B = Rectangle(4,8)" << endl;
    B = Rectangle(4,8);
    cout <<"Shape B is a " << B  << "The area of B = " << B.getArea() << endl << endl;

    if(A<B)
        cout << "A is smaller than B" << endl;
    if(B<A)
        cout << "A is larger than B" << endl;

    return 0; 
}