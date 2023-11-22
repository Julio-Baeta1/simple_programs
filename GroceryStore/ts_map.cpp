#include <iostream>
#include <unordered_map>
#include <string>
#include <thread>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <vector>
#include <algorithm>
#include <chrono> 

using std::string;
using std::vector;
using std::pair;
using std::printf;
using std::thread;
using std::ref;
using std::atomic;

class TsMap
{
    private:
        std::shared_mutex shared_mut;
        std::unordered_map<std::string,int> order_map;

    public:
        TsMap(){};

        void populate(vector<string>* prod, vector<int>* amount, atomic<int>& count)
        {
            std::unique_lock lock(shared_mut);
            for(int i=0; i < prod->size(); i++){
                order_map[prod->at(i)] = amount->at(i);
                count++;
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

        void removeEntry(string item)
        {
            std::unique_lock lock(shared_mut);
            order_map.erase(item);
        }

        int size()
        {
            std::shared_lock lock(shared_mut);
            return order_map.size();
        }

};


static void getListItems(TsMap& order, vector<string>& items, int thrd_id, atomic<int>& count)
{
    pair<string,int> temp;
    while(count > 0){
        for(auto& item: items)
        {
            temp = order.get(item);

            if(temp.first != "Not found"){
                count--;
                std::this_thread::sleep_for (std::chrono::seconds(thrd_id*2));
                printf("Thread %i got %iX %s\n",thrd_id,temp.second,temp.first.c_str());
                order.removeEntry(temp.first);
            }
        }
    }
}

static void customer(TsMap& order,vector<string>& items,vector<int>& amounts,atomic<int>& count)
{
    for(int i=0; i < items.size(); i++){
        std::this_thread::sleep_for (std::chrono::seconds(2));
        order.addEntry(items.at(i),amounts.at(i));
        count++;
        printf("Customer added %iX %s to the order\n",amounts.at(i),items.at(i).c_str() );
    }
}

int main(int argc, const char *argv[]){
    
    vector<string> order_product{"apple","bean can","beef","potatoes","chicken","floor cleaner","box pasta","washing powder"};
    vector<int> order_amount{2,5,2,6,1,3,2,1};
    atomic<int> count{0};

    printf("Populates orders\n");
    TsMap order;
    order.populate(&order_product,&order_amount,count);

    vector<string> extra_product{"1kg flour","tomatoes","fish","tomato sauce","watermelon"};
    vector<int> extra_amount{1,2,1,3,1};

    vector<string> fruit_and_veg{"apple","pear","potatoes","tomatoes","watermelon","pumpkin"};
    vector<string> meats{"beef","chicken","pork","lamb","fish"};
    vector<string> dry_goods{"box pasta","bean can","1kg flour","bag rice","tomato sauce"};
    vector<string> cleaning{"washing powder","floor cleaner"};

    vector<thread> threads;
    threads.push_back(thread(customer,ref(order),ref(extra_product),ref(extra_amount),ref(count)));

    threads.push_back(thread(getListItems,ref(order),ref(fruit_and_veg),1,ref(count)));
    threads.push_back(thread(getListItems,ref(order),ref(meats),2,ref(count)));
    threads.push_back(thread(getListItems,ref(order),ref(dry_goods),3,ref(count)));
    threads.push_back(thread(getListItems,ref(order),ref(cleaning),4,ref(count)));
    
    for(thread& thread_to_join : threads)
        thread_to_join.join();

    std::printf("Thread safe Map size = %i\n", order.size());

    return 0;
}