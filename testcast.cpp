#include<iostream>
#include <typeinfo>
using namespace std;

class Base
{
    public:
        Base()=default;
        virtual ~Base()=default;
        virtual void print()
        {
            cout << "Base::print() called " << endl;
        }
        virtual void funB()
        {
            cout << "Base::funB() called " << endl;
        }
};

class Derived: public Base
{
    public:
        Derived()=default;
        virtual ~Derived()=default;
        virtual void print()
        {
            cout << "Derived::print() called " << endl;
        }
        virtual void funB()
        {
            cout << "Derived::funB() called " << endl;
        }
        void funD()
        {
            cout << "Derived::funD() called " << endl;
        }
};

void GoodDynamicCast(Base* ptrB)
{
    cout << "== good dynamic case\n";
    Derived *ptrD=dynamic_cast<Derived*>(ptrB);

    ptrD->print();
    ptrD->funB();
    ptrD->funD();
}


void BadDynamicCast()
{
    cout << "== bad dynamic case\n";
    Base *br=new Base;
    try{
        //Derived &dr=dynamic_cast<Derived&>(*br);
        Derived *dr=dynamic_cast<Derived*>(br);
        cout << "address= " << dr <<endl;
        }
    catch(const bad_cast&)
    {
        cout << "bad cast\n";
    }
}

int main()
{
    Base *ptrB =new Base;
    Derived *ptrD=new Derived;

    cout << "==conversion from base class to derived class" << endl;
    ptrD=static_cast<Derived *>(ptrB);
    ptrD->print();
    ptrD->funB();
    ptrD->funD();

    cout << "==conversion from derived class to base class" << endl;
    //ptrB=static_cast<Base *>(ptrD);
    ptrB=ptrD;
    ptrB->print();
    ptrB->funB();

    cout << "------------------------------------------------" <<endl;
    Base *pB=nullptr;
    Derived *pD=new Derived;
    pB=pD;
    GoodDynamicCast(pB);
    BadDynamicCast();

    cout << "------------------------------------------------" <<endl;

    return 0;
}
