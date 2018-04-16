#include <iostream>
#include <vector>
#include <algorithm>

void Add(int a)
{
    std::cout << (a+10) << std::endl;
}


int main()
{
    double prices[5]={2.3,3.2,5.6,8.9};
    for(auto x:prices)
    {
        std::cout << x << std::endl;
    }
    std::cout << " *******************************"<<std::endl;
    for(auto &x:prices)
        x=x*0.9;

    for(auto x:prices)
    {
        std::cout << x << std::endl;
    }

   std::cout << " *******************************"<<std::endl;
   std::vector<int> intVec{1,5,10,4};
    for_each(intVec.begin(),intVec.end(),Add);
    for(auto x:intVec)
    {
        std::cout << x << std::endl;
    }
    for(auto x:intVec)
        Add(x);
    for(auto x:intVec)
    {
        std::cout << x << std::endl;
    }
    std::cout << " *******************************"<<std::endl;
    std::cout << " *******************************"<<std::endl;
    std::cout << " *******************************"<<std::endl;
    return 0;
}
