#include<iostream>


template<int firstValue,int secondValue>
struct get_min_value
{
    //static const int value = (firstValue < secondValue)? firstValue : secondValue;
    static const int value = 0;
    if(firstValue < secondValue)
        value = firstValue;
};

int main()
{
    std::cout << get_min_value<10,20>::value << std::endl;
    return 0;
}
