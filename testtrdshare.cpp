#include<iostream>
#include<thread>
#include <mutex>

using namespace std;

#define COUNT 10000000

static mutex g_mutex;

static void procFun(int *p)
{
    for(int i=0;i<COUNT;i++)
    {
   //     g_mutex.lock();
        lock_guard<mutex> _(g_mutex);
        (*p)++;
   //     g_mutex.unlock();
    }
}

void HandleThreadData(void)
{
    int shareData = 0;
    //atomic<long> shareData(0);
    thread threadA(procFun,&shareData);
    thread threadB(procFun,&shareData);

    threadA.join();
    threadB.join();
    cout << "shareData= " <<shareData<< endl;
}

int main()
{
    HandleThreadData();
    return 0;
}
