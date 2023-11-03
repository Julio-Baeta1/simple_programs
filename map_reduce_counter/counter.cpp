#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <memory>
#include <functional>

using namespace std;

void printMap(map<int,int>* m){

    int tol{0};

    for_each(m->begin(), m->end(), 
        [&tol](pair<int, int> p) { 
            cout << p.first << ": " << p.second << endl; 
            tol += p.second ;
        }); 

    printf("The total number of elements is: %d",tol);
    
}

void genRandElems(vector<int> *x, int seed, int lim){
    //Random generator
    mt19937 r_gen (seed);
    function<void(int&)> rGen = [&] (int& a) {a = r_gen()%lim;};

    //Create vector of random positive ints less than lim=10 
    for_each(x->begin(), x->end(), rGen);
}

void standardCount(map<int,int>* counter, int seed, int lim, int n_elem)
{

    vector<int> x(n_elem,0);
    genRandElems(&x, seed,lim);

    //If elem in counter freq++, else insert it into counter with freq=1
    for(auto& elem: x)
    {
        auto iter = counter->find(elem);

        if(iter != counter->end())
            iter->second++;
        else
            counter->operator[](elem) = 1;        
    }

}


int main(int argc, const char *argv[]){

    int seed{0}, lim{10}, n_elem{200};
    map<int,int> m;
    standardCount(&m,seed,lim,n_elem);
    printMap(&m);
    
    /*string test{"one two three one two one one two four three one two"};
    stringstream ss(test);
    string word{""};
    vector<string> words;
    
    while(ss >> word)
    {
        words.push_back(word);
    }

    map<string,int> counter;
    map<string,int>::iterator iter;

    for(auto& word:words)
    {
        iter = counter.find(word);

        if(iter != counter.end())
            iter->second++;
        else
            counter[word] = 1;            
    }

    for_each(counter.begin(), counter.end(), 
        [](pair<std::string, int> p) { 
            cout << p.first << ": " << p.second << endl; 
        }); 
    */
    return 0;
}