#include<iostream>
#include<memory>
#include<string>
using namespace std;

class CReport
{
    public:
        CReport(string s)
        {str=s;cout << "in constructor" << endl;}
        ~CReport()
        {cout << "in ~destructor" << endl;}
        void Comment()
        {cout << str << endl;}
    private:
        string str;
};

void doubleDelete()
{
    CReport* pr=new CReport("test shared pointer");
    shared_ptr<CReport> shared_ptr1(pr);
    shared_ptr<CReport> shared_ptr2(pr);
}

void noDoubleDelete()
{
    auto shared_ptr1 = make_shared<CReport>("test shared pointer");
    auto shared_ptr2(shared_ptr1);
}


class A
{
    public:
        A():m_(10){}
        void fun() {cout << "val: "<< m_ << endl;}
    private:
        int m_;
};

shared_ptr<A> fun()
{
    auto ptr=make_shared<A>();
    return ptr; // std::move() wwill be called
}

int main(void)
{
    /*
    {
        auto_ptr<CReport> ps(new CReport("Using auto_ptr."));
        ps->Comment();

        auto_ptr<CReport> p1;
        p1=ps;
    }
    */
    {
        shared_ptr<CReport> ps(new CReport("Using shared_ptr."));
        ps->Comment();

        shared_ptr<CReport> p1;
        p1=ps;
    }

    {
        unique_ptr<CReport> ps(new CReport("Using unique_ptr."));
        ps->Comment();

 //       unique_ptr<CReport> p1;
 //       p1=ps;
    }

    auto ps=make_unique<CReport>("Using unique_ptr");

//    ps->Comment(string("ps: "));

    //auto intArray=make_shared<int[]>(10);
    //auto intArray1=make_unique<int[]>(10);

    auto sp=fun();
    sp->fun();
    auto p1=make_unique<int[]>(10);
    unique_ptr<int[]> p2=std::move(p1);
    //unique_ptr<int> p2=p1; // copy constructor of unique_ptr is deleted.
    cout << "p2= " << p2[0] << p2[1] << p2[3] << endl;


  //  cout << "p1= " << *p1 << endl;
 //   cout << p1 << endl; //p1 is 0.

    return 0;
}
