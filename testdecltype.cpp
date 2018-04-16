#include <iostream>
template<typename T,typename U>

auto multiply(T t,U u) -> decltype(t*u)
{
    return t*u;
}

int main()
{
    //double x;
    //int n;
    //decltype(x*n) q;
    std::cout << multiply(2.0,2.0) << std::endl;
    int i=0;
    std::cout <<&(i++) << " , " << &(++i) << std::endl;
    return 0;
}
