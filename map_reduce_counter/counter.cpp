#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;


int main(int argc, const char *argv[]){

    int seed{0}, lim{10}, n_elem{200};

    //Random generator
    mt19937 r_gen (seed);
    auto rGen = [&] (int& a) {a = r_gen()%lim;};

    //Create vector of random positive ints less than lim=10 
    vector<int> x(n_elem,0);
    for_each(x.begin(), x.end(), rGen);

    map<int,int> counter;
    map<int,int>::iterator iter;

    //If elem in counter freq++, else insert it into counter with freq=1
    for(auto& elem:x)
    {
        iter = counter.find(elem);

        if(iter != counter.end())
            iter->second++;
        else
            counter[elem] = 1;            
    }

    for_each(counter.begin(), counter.end(), 
        [](pair<int, int> p) { 
            cout << p.first << ": " << p.second << endl; 
        }); 

    

    
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