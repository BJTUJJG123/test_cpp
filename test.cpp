/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Jul 2019 10:32:28 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include "test.hpp"
#include <thread>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <mutex>

using namespace std;
using std::vector;
void helloword()
{
   cout << "hello world \n" << endl;
}

struct Counter
{
    mutex mux;
    int val;
    Counter(): val(0) {}

    void increment()
    {
       mux.lock();
       ++val;
       mux.unlock();
    }

    void decrement(){
        std::lock_guard<mutex> guad(mux);

      if(val ==0)
          throw "value less than 0";

      --val;
    }
};

int main(void)
{
    struct Counter counter;

     vector<std::thread> threads;
     for (int i = 0; i < 5; ++i)
     {// 使用lambda 定义要执行的代码
        threads.push_back(std::thread(
                    [&counter](){
                    cout << "hello word " << this_thread::get_id() << endl;
                    for(int j = 0; j < 100; ++j)
                    {
                      counter.increment();
                    }
                    for(int k = 0; k < 10; ++k)
                    {
                      counter.decrement();
                    }
                    }));
     }
     /*捕获列表 参数列表 函数体  */
     cout << "hello word in main proram"<< endl;
     for(auto &thread:threads)
     {
        thread.join();
     }

    cout << counter.val << endl;
  //   t1.join();
/*     int a[] = {8,6,4,2,0,1,3,9,7,99};
     QuickSort(a, 0, 9);
     for(int i = 0; i < 10; i++)
         cout << a[i] << endl;
*/
     return 0;
}
