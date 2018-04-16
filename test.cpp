#include <iostream>
#include <vector>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;

class A
{
    public:
        A(){};
        A(short s):a(s),arr{}{};
        void print() { cout << b << endl;};
    private:
        short a;
        int b=10;
        int arr[5]{0,1,2,3,4};
};

void fun(int i) {cout << i << endl;}
/*
int sum(initializer_list<int> lst)
{
    int total=0;
    for(const auto& value:lst)
        total+=value;
    return total;
}*/

enum class AA{E_RED,E_BLUE,E_GREEN};
enum class BB{E_RED,E_GRAY};
enum class ESHORT:short{E_RED,E_BLUE,E_GREEN};

int main()
{
    // 1
    short array[5]{4,5,2,76,1};
    std::vector<int> ivec{1,2,3};
    for(int i=0;i<5;i++)
    {
        cout << array[i] << endl;
    }
    for(int i=0;i<3;i++)
    {
        cout << ivec[i] << endl;
    }
    cout<<"----------------------------------" <<endl;

    // 2
    fun({3.14}); // has warning
    fun(5.20); //no warning
    cout<<"----------------------------------" <<endl;

    //3
/*    int a=sum({1,2,3});
    int b=sum({10,20,30,40});
    int c=sum({1,2,3.0}); */
    cout<<"----------------------------------" <<endl;

    //4
    A a;
    a.print();
    cout<<"----------------------------------" <<endl;
    //5 enum
    AA eA=AA::E_RED;
    BB eB=BB::E_RED;
//    cout << eA << " " << eB << endl;
    cout << sizeof(ESHORT) << endl;
    cout<<"----------------------------------" <<endl;

    cout<<"----------------------------------" <<endl;
    return 0;
}
