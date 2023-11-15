#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <functional>

using string = std::string;

template<typename key>
void printMap(std::map<key,int>* m){

    int tol{0};

    for_each(m->begin(), m->end(), 
        [&tol](std::pair<key, int> p) { 
            std::cout << p.first << ": " << p.second << std::endl; 
            tol += p.second ;
        }); 

    printf("The total number of elements is: %d \n",tol);
    
}


template<typename T>
void genRandElems(std::vector<T>* x, int lim=10, int seed=0)
{
    std::mt19937 r_gen (seed);
    std::uniform_int_distribution<> dis(0, lim);
    std::function<void(int&)> rGen = [&] (int& a) {a = dis(r_gen);};
    for_each(x->begin(), x->end(), rGen);
}

template<>
void genRandElems(std::vector<string>* x, int lim, int seed)
{
    std::mt19937 r_gen (seed);
    string letters{ "abcdefghijklmnopqrstuvwxyz" };
    int word_length = 3;
    if(lim-- > letters.length())
        lim = letters.length();
    std::uniform_int_distribution<> dis(0, lim);

    std::function<void(string&)> rGen = [&] (string& A) {
        for(int i=0; i<word_length; i++)
            A += letters[dis(r_gen)];
    };

    for_each(x->begin(), x->end(), rGen);
}


template<typename key, int N>
void standardCount(std::map<key,int>* counter, int lim, int seed=0)
{

    std::vector<key> x(N);
    genRandElems(&x,lim,seed);

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

    int seed{0}, lim_int{8}, lim_str{2} ;
    std::map<int,int> m;
    standardCount<int,200>(&m,lim_int);
    printMap<int>(&m);

    std::map<string,int> s;
    standardCount<string,200>(&s,lim_str);
    printMap<string>(&s);

    return 0;
}