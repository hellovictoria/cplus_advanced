#include <iostream>
using namespace std;

class A
{
    public:
        A()=default;
        //A(int i):a(i){cout << "int a="<<a<<endl;}
        explicit A(int i):a(i){cout << "int a="<<a<<endl;}
        explicit A(short i):a(i){cout <<"short a=" <<a<<endl;}
        A(char i):a(i){cout <<"char a=" <<a<<endl;}
        A& operator=(A&r){cout<<"oper=\n";}
        ~A(){}
    private:
        int a=1;
};

int main()
{
    A objA1=10;
    //explicit A(int i):a(i){cout <<"int a="<<a<<endl;}
    //A objA=10;
    A objA2=(A)10;
    return 0;
}
