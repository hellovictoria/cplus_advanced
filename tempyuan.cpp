#include<iostream>
#include<stdio.h>

using namespace std;

template<unsigned char f>
class Factorial
{
    public:
        //static const unsigned long long value = (f*Factorial<f-1>::value);
        const unsigned long long value = (f*Factorial<f-1>::value);
};

template<>
class Factorial<0>
{
    public:
        //static const unsigned long long value=1;
        const unsigned long long value=1;
};

int main()
{
    cout << Factorial<6>::value << endl;
    return 0;
}
