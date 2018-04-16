#include<iostream>

using namespace std;

class A
{
    public:
        A():ia(1),ca('a'){};
        A(int i,char c){ia=i;ca=c;};
        void print() { cout << ia<<"," << ca <<endl;}
        virtual ~A(){};
    private:
        int ia;
        char ca;
};

A ConstCast(const A& val,const A b)
{
    A *valueAfterConstCast = const_cast<A *>(&val);
    *valueAfterConstCast =b;

    cout << "class A,address of variable valueAfterConstCast: " << valueAfterConstCast << endl;
    cout << "class A,address of variable val: " << &val <<endl;

    return (*valueAfterConstCast);
}

int ConstCast(const int& val,const int b)
{
    int *valueAfterConstCast = const_cast<int *>(&val);
    *valueAfterConstCast =b;

    cout << "address of variable valueAfterConstCast: " << valueAfterConstCast << endl;
    cout << "address of variable val: " << &val <<endl;

    return (*valueAfterConstCast);
}

int main()
{
    const int val=10;
    cout << "before const cast, &val= " << &val << endl;
    cout << "value after const cast= " << ConstCast(val,100) << endl;
    cout << "val after const cast= " << val << endl;

    cout << "------------------------------------------------------" << endl;
    const A valA;
    const A valB(2,'b');
    valA.print();
    cout << "class A,before const cast, &valA= " << &valA << endl;
    cout << "class A,value after const cast= ";
    ConstCast(valA,valB).print();
    cout << "class A,val after const cast= ";
    valA.print();
    return 0;
}
