#include<iostream>
#include<functional>
using namespace std;

function<int(void)> multiplyBy2Lambda(int x)
{
    return [x]{return x*x;};
}

int main()
{
    auto fn=multiplyBy2Lambda(5);
    cout << "fn=" <<fn() << endl;
}
