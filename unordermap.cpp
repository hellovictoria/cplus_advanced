#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

int main()
{
    std::unordered_map<int,std::string> m = {
        {1,"str_one"},
        {2,"str_two"},
        {3,"str_three"},
        {4,"str_four"},
        {2,"str_two_2"}
        };

    for(const auto&p : m)
    {
        std::cout << p.first << "=" << p.second << std::endl;
    }
}
