#include <stdio.h>
#include <iostream>

using namespace std;

//void fun(){}

template<typename T,typename... Args>
void fun(T value, Args... args)
{
    cout << value << ",";
    fun(args...);
}

int main()
{
    int a=10;
    double b=1.41;
    string str="hello";
    fun(b,'c',8,str);
}
