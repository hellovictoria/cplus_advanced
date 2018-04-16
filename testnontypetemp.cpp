#include<iostream>
#include<string>

using namespace std;

template<int VAL>
double process(double v)
{
    return v*VAL;
}

template<int VAL>
double isLessThanSpecificValue(int para)
{
    return para<VAL;
}


int main()
{
    cout << isLessThanSpecificValue<3>(2) << endl;
}
