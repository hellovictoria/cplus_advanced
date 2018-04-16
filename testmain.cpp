#include<list>
#include<iostream>
#include<string>
#include "Stack.hpp"
using namespace std;


int main()
{
    Stack<string> strStack;
    strStack.push("hello");
    strStack.push("world");
    cout << strStack.pop() << endl;
    cout << strStack.pop() << endl;

    Stack<int> intStack;
    return 0;
}
