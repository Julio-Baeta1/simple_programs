#include <iostream>
#include <memory>
#include "shape.h"

using std::cout, std::endl, std::make_unique; 

int main()
{
    Shape s1(3);
    cout << "s1 has " << s1.getNumSides() << " sides" << endl << endl;

    Shape s2(s1);
    cout << "s1 has " << s1.getNumSides() << " sides" << endl;
    cout << "s2 has " << s2.getNumSides() << " sides" << endl << endl;

    cout << "set s1 to have 4 sides" << endl;
    s1.setNumSides(4);
    s2 = s1;
    cout << "s1 has " << s1.getNumSides() << " sides" << endl;
    cout << "s2 has " << s2.getNumSides() << " sides" << endl << endl;

    Shape s3(std::move(s1)); //std::move turns an lvalue into an rvalue
    cout << "Recall s1 originally had 4 sides" << endl;
    cout << "s1 has " << s1.getNumSides() << " sides" << endl;
    cout << "s3 has " << s3.getNumSides() << " sides" << endl << endl;

    cout << "Create an rvalue Shape with 3 sides" << endl;
    s1 = Shape(3);
    cout << "s1 has " << s1.getNumSides() << " sides" << endl<< endl;

    return 0; 
}