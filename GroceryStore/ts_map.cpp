#include <iostream>
#include <unordered_map>
#include <string>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <algorithm>
#include <chrono> 

using std::string;
using std::vector;
using std::pair;
using std::printf;
using std::thread;
using std::ref;

class TsMap
{
    private:
        std::shared_mutex shared_mut;
        std::unordered_map<std::string,int> order_map;

    public:
        TsMap(){};

        void populate(vector<string>* prod, vector<int>* amount)
        {
            std::unique_lock lock(shared_mut);
            for(int i=0; i < prod->size(); i++){
                order_map[prod->at(i)] = amount->at(i);
            }
        }

        void printAll()
        {
            int tot{0};
            std::shared_lock lock(shared_mut);

            std::for_each(order_map.begin(),order_map.end(),[&tot] (pair<string,int> p){
                printf("%s : %i\n",p.first.c_str(),p.second);
                tot += p.second;
            });
            printf("Total: %i",tot);
        }

        pair<string,int> get(string item)
        {
            std::shared_lock lock(shared_mut);
            auto iter = order_map.find(item);

            if(iter != order_map.end())
                return *iter;
            
            return std::make_pair("Not found",0);
        }

        void addEntry(string prod, int amount)
        {
            std::unique_lock lock(shared_mut);
            order_map[prod] = amount;        
        }

};


static void getListItems(TsMap& orders, vector<string> items, int thrd_id)
{
    pair<string,int> temp;
    for(auto& item: items)
    {
        temp = orders.get(item);

        if(temp.first != "Not found"){
            printf("Thread %i going to get %iX %s\n",thrd_id,temp.second,temp.first.c_str());
            std::this_thread::sleep_for (std::chrono::seconds(1));
            printf("Thread %i got %iX %s\n",thrd_id,temp.second,temp.first.c_str());
        }
    }
}

int main(int argc, const char *argv[]){
    
    vector<string> order_product{"apple","bean can","beef","potatoes","chicken","floor cleaner","box pasta","washing powder"};
    vector<int> order_amount{2,5,2,6,1,3,2,1};

    printf("Populates orders\n");
    TsMap orders;
    orders.populate(&order_product,&order_amount);

    vector<string> fruit_and_veg{"apple","pear","potatoes","tomatoes","watermelon","pumpkin"};
    vector<string> meats{"beef","chicken","pork","lamb","fish"};

    vector<thread> threads;
    threads.push_back(thread(getListItems,ref(orders),fruit_and_veg,1));
    threads.push_back(thread(getListItems,ref(orders),meats,2));
    
    for(thread& thread_to_join : threads)
        thread_to_join.join();

    return 0;
}