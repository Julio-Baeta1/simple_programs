#include <iostream>
#include <memory>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

using std::cout, std::endl, std::make_unique; 

int main()
{
    Rectangle A(4.0,2.0);
    cout <<"Shape A is a " << A  << "The area of A = " << A.shapeArea() << endl;

    Circle B(1);
    cout <<"Shape B is a " << B << "The area of B = " << B.shapeArea() << endl;

    auto C = dynamic_cast<Shape*>(&B); 
    cout << "dynamic cast Circle B to Shape ptr C" << endl;
    cout << "Area of C = " << C->shapeArea() << endl << endl;

    cout << "Will B fit into A?" << endl;
    //Do not need explicit dynamic casting as the base class for B is Shape only pass a pointer to B which will act as a Shape ptr.
    if (A.shapeFit(&B))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Will A fit into B?" << endl;
    if (B.shapeFit(&A))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0; 
}