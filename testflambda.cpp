#include<iostream>
#include<algorithm>
#include<vector>
#include<typeinfo>
using namespace std;

int main()
{
    vector<int> intVec{10,20,30,105,209};

    auto isGreaterThan100 =[](auto i){return i>100;};
    auto intlter=find_if(intVec.begin(),intVec.end(),isGreaterThan100);

    if(intlter!=intVec.end())
    {
        cout << "found a value > 100:" <<*intlter << endl;
    }

    while((iter=find_if())!=intVec.end())
    {

    }
    return 0;
}
