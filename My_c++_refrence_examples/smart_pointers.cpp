#include <iostream>
#include <memory>
#include <string>

using std::cout, std::endl, std::string;
using std::unique_ptr, std::make_unique;
using std::shared_ptr, std::make_shared;

class X
{
    private:
        int val;
    public:
        X(int x){val = x;}
        int get() const {return val;}
        void print(string name="default") {cout<<name<<": "<<val<<endl;}
        void incr(int amount) {val+=amount;}
};

void makeNeg(X* x, string msg){
    int neg = -1*x->get();
    x->incr(2*neg);
    x->print("makeNeg for " + msg);
}

unique_ptr<X> makeNegUni(unique_ptr<X> x, string msg){
    int neg = -1*x->get();
    x->incr(2*neg);
    x->print("makeNegUni for " + msg);
    return std::move(x);
}

void useSharedPtrByValue(shared_ptr<X> sp){
    sp->incr(1);
    sp->print("useSharedPtrByValue");
}

void useSharedPtrByReference(shared_ptr<X>& sp){
    sp->incr(1);
    sp->print("useSharedPtrByReference");
}
void useSharedPtrByConstReference(const shared_ptr<X>& sp){
    sp->incr(1);
    sp->print("useSharedPtrByConstReference");
}


int main(int argc, const char *argv[]){

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Make_unique copy constructor
    X a(1);
    X* a_ptr = &a;
    
    auto x1 = make_unique<X>(a);
    auto x2 = make_unique<X>(a);
    auto x3 = make_unique<X>(-5); //create an X
    //Cannot
    // unique_ptr x2 = make_unique<X>(a_ptr);

    a.incr(1);
    x1->incr(10);
    x2->incr(3);

    a_ptr->print("a");
    x1->print("x1");
    x2->print("x2");
    x3->print("x3");

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Unique ownership

    auto x4 = std::move(x1);

    if(x1 == nullptr)
        cout << "x1 points to no object" << endl;
    else
       cout << "x1 points to an object" << endl; 

    x4->print("x4");

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    makeNeg(x4.get(),"x4");
    x4->print("x4 after makeNeg");

    x4 = std::move(makeNegUni(std::move(x4),"x4")); //Don't do this its just to illustarte
    x4->print("x4 after makeNegUni");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shared pointer constructor

    auto s1 = make_shared<X>(0);
    auto s2(s1);

    s1->incr(4);
    s2->incr(5);

    s1->print("s1");
    s2->print("s2");

    X b{0};
    shared_ptr<X> s3(&b);
    b.print("b");
    s3->print("s3");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    auto s4 = make_shared<X>(0);
    s4->print("s4");

    // Pass the shared_ptr by value. This invokes the copy constructor
    useSharedPtrByValue(s4);
    s4->print("s4 after useSharedPtrByValue");

    // Pass the shared_ptr by reference or const reference.
    useSharedPtrByReference(s4);
    useSharedPtrByConstReference(s4);
    s4->print("s4 after useReferences");


    return 0;
}
