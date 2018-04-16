#include<iostream>
using namespace std;
template<typename T>
int fun(T)
{
    return 1;
}

template<typename T>
int fun(T*)
{
    return 2;
}


template<typename T1,typename T2>
void foo(T1,T2)
{
    cout << "foo(T1,T2)" << endl;
}

template<typename T1,typename T2>
void foo(T2,T1)
{
    cout << "foo(T2,T1)" << endl;
}

int main()
{
    cout << fun<int>((int*)0) << endl;
    cout << fun<int*>((int*)0) << endl;
    //cout << fun<int>((int*)0) << endl;
    cout << fun(0) << endl;
    cout << fun((int*)0) << endl;
    foo<int,char>(10,'a');
    foo<int,char>('a',10);
    //foo<char,char>('a','b');
    return 0;
}
