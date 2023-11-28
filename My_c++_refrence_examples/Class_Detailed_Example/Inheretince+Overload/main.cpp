#include <iostream>
#include <memory>
#include "shape.h"
#include "rectangle.h"

using std::cout, std::endl, std::make_unique; 

int main()
{
    Rectangle A(4.0,2.0);
    A.prettyPrint();
    cout << "Area of A = " << A.getArea() << endl;

    Rectangle A1(A);
    cout << "copy constructor A1(A)" << endl;
    A1.prettyPrint();

    Rectangle B(std::move(A1));
    cout << "move constructor B(A)" << endl << "B:" << endl;
    B.prettyPrint();
    cout << "A1:" << endl;
    A1.prettyPrint();

    cout << "Copy assignment A1 = A" << endl;
    cout << "A1:" << endl;
    A1.prettyPrint();

    cout << "Move Assigment B = Rectangle(4,8)" << endl;
    B = Rectangle(4,8);
    B.prettyPrint();
    cout << "Area of B = " << B.getArea() << endl;

    if(A<B)
        cout << "A is smaller than B" << endl;
    if(B<A)
        cout << "A is larger than B" << endl;


    return 0; 
}