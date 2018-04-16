#include<iostream>
#include<stdio.h>

#include "tempClassA.hpp"

using namespace std;

int main()
{
    A<int> intA;
    intA.fun(1,10);
    return 0;
}
