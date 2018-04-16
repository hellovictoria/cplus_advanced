#include <iostream>
#include <thread>

using namespace std;

void initialFun()
{
    cout << "thread id = " << std::this_thread::get_id() << endl;
}

class Counter
{
    public:
        Counter(int a,int b):mId(a),mNumIterations(b)
        {cout << "Counter constructer is called\n";}
        void operator()() const
        {
            for(int i=0;i<mNumIterations;++i)
            {
                cout << "counter" << mId << "has value";
                cout << i << endl;
            }
        }
    private:
        int mId;
        int mNumIterations;
};

int main()
{
    std::thread td(initialFun);
    cout <<"joinable before join called = " << boolalpha << td.joinable() << endl;
    td.join(); //waiting for thread ending
    cout <<"joinable after join called = " << boolalpha << td.joinable() << endl;

    cout << "main thread id: " << std::this_thread::get_id() << endl;

    thread t1{Counter{1,10}};
    t1.join();

    Counter c(1,10);
    thread t2(c);
    t2.join();

    thread t3(Counter(1,10));
    t3.join();

    return 0;
}
