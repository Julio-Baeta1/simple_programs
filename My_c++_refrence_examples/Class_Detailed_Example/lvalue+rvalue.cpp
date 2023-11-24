/*  lvalue vs rvalue
    ----------------

    lvalue: Expression that identifies a non-temporary object e.g. int x and int y are both lvalues.
    rvalue: Expression that identifies a temporary object or a value(e.g. literal constant) not associated with any object.
            e.g. 2 and x+y are both rvalues.

    int z(lvalue) = x + y (rvalue);

    General rule if it is named it is an lvalue. 
    
    An operator call such as in arr[1] or *ptr can be both an lvalue or rvalue depending on function context.

    string str = "Some string";
    lvalue reference declarartion
        string & alias = str;
    rvalue reference declaration
        string && temp = str


    std::move(x) turns x into an rvalue, which is moveable.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using std::cout, std::endl, std::vector;

double average(double a, double b){
    return (a+b)/2;
}

void swap(double& a, double& b){
    std::swap(a,b);
}

template<typename T>
T randElem(const vector<T>& vec){
    return vec.at(2);
}


int main()
{
    int x{2};
    vector<int> A{1,2,3,4,5};

    cout << "lvalue reference Alias example" << endl << "x_alias is an alias for x used in the case when x is a complex expression." 
        << endl;
    cout << "x: " << x << endl;
    int & x_alias = x;
    cout << "only incrementing x_alias by one gives" << endl;
    x_alias++;
    cout << "x: " << x << endl << endl;

    cout << "lvalue reference range based for loops example" << endl << "A is range 1->5, if auto& not used than we will only incr"
    << " a copy and not the original elements" << endl;
    cout << "A[2]: " << A.at(2) << endl;
    for(auto& a:A)
        ++a ;
    cout << "A[2]: " << A.at(2) << endl << endl;

    cout << "lvalue avoiding copying example" << endl << "Stops unnessary making of a copy of the result of a function" << endl;
    cout << "A[4]: " << A.at(4) << endl;
    auto & m = *std::max_element(A.begin(),A.end());
    cout << "confirm m is A[4] by setting m to 0" << endl;
    m = 0;
    cout << "A[4]: " << A.at(4) << endl << endl;



    cout << "Parameter passing:" << endl;
    double a{4},b{6};
    vector<int> S{1,2,3,4,5};
    
    cout << "Call by value" << endl << "Use for small objects that must not be altered by the function."<<endl << endl;
    double z = average(a,b);

    cout << "Call by reference:" << endl << "Use for objects that must be altered by the function."<<endl;
    cout << "Original a: " << a << " ,original b: " << b << endl;
    swap(a,b);
    cout << "After swap a: " << a << " ,after swap b: " << b << endl << endl;

    cout << "Call by const reference:" << endl << "Use for objects that must not be altered by the function."<<endl;
    auto s = randElem(S);

    return 0;
}