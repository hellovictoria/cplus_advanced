#include<iostream>

using namespace std;

class A
{
    public:
        A():ia(1),ca('a'),da(0.1){};
        virtual ~A(){};
        A(int i,char c,double d){this->ia=i;this->ca=c;this->da=d;};
        A(const A& vala)
        {
            cout <<"copy constructor." <<endl;
            this->ia=vala.ia;
            this->ca=vala.ca;
            this->da=vala.da;
        }
        A& operator= (const A& other)
        {
            cout << "operator=" << endl;
            if(this == &other)
                return *this;
            this->ia=other.ia;
            this->ca=other.ca;
            this->da=other.da;
            return *this;
        }

        A(A&& vala)
        {
            cout << "move copy constructor." << endl;
            this->ia = vala.ia;
            this->ca=vala.ca;
            this->da=vala.da;
            vala.ia=0;
            vala.ca='\0';
            vala.da=0.0;
        }

        A& operator= (A&& other) noexcept
        {
            cout << "move operator= " << endl;
            if(this==&other)
                return *this;
            this->ia=other.ia;
            this->ca=other.ca;
            this->da=other.da;
            other.ia=0;
            other.ca='\0';
            other.da=0.0;
            return *this;
        }

    private:
        int ia;
        char ca;
        double da;
};


int main()
{
    A a1;
    A a2(2,'b',0.2);
    a1=a2;
    A a3=a2;
    A a4(a3);
    A a5(std::move(a3));
    A a6;
    a6=std::move(a3);
   
    return 0;
}
