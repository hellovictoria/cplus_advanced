#include<stdio.h>
#include<iostream>
using namespace std;

template<typename T>
class A
{
    public:
        A(){}
        ~A(){}
        void fun(int x,const T& y){cout << x+y<< endl;}
        T& get(){}
};


int main()
{
    A<int> intA;
    intA.fun(1,10);
    return 0;
}
