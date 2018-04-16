#include <iostream>
#include <functional>

using namespace std;


function<int(void)> multiplyBy2Lambda(int x)
{
    return [x]{return 2*x;}; // what does the [x] mean?
}

int main()
{
    auto fn=multiplyBy2Lambda(5);
    cout << "fn=" <<fn() << endl;   //int(void) means fn's return value is int, fn has no params.


    int a=1,b=2;
    auto getSumOfTwoValue=[](int a,int b)->int{return a+b;};
    int sum = getSumOfTwoValue(a,b);
    cout << sum << endl;

    int val=10;
    auto captureVarInScope =[&val]{val+=1;cout << "val="<<val<<endl;};
    captureVarInScope();

    int val2=10;
    auto captureVarInScope2=[val2]() mutable{val2+=1;cout<< "val2="<<val2<<endl;};
    captureVarInScope2();
    return 0;
}
