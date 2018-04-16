#include <iostream>

void increase(int& val)
{
    std::cout << "increase(int& val) is called" << std::endl;
    ++val;
}

void increase(int&& val)
{
    std::cout << "increase(int&& val) is called" << std::endl;
    ++val;
}

int main()
{
    int a=5;
    int b=10;

    increase(a);
    std::cout << "a=" << a <<std::endl;

    increase(a+b);

    increase(std::move(a)); //move a to r value
    std::cout << "move:a=" << a<<std::endl;

    std::cout << "a=" << a << "," <<"b=" <<b << std::endl;
    return 0;
}
