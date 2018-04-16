#include <iostream>
#include <string>

using namespace std;

template<unsigned char f>
class Factorial
{
    public:
        static const unsigned long long value =(f*Factorial<f-1>::value);
};

template<>
class Factorial<0>
{
    public:
       static  const unsigned long long value=1;
};

template<int a,int b>
struct get_min_value
{
    static const int value=(a<b)?a:b;
};

template<bool b>
struct If;

template<>
struct If<true>
{
  static void Fun()
  {cout << "if control struct: true" <<endl;}
};

template<>
struct If<false>
{
  static void Fun()
  {cout << "if control struct: false" <<endl;}
};

template<typename T>
void process_helper(const T& t,true_type)
{
    cout << t << " is an integral type" << endl;
}

template<typename T>
void process_helper(const T& t,false_type)
{
    cout << t << " is not an integral type" << endl;
}

template<typename T>
void process(const T& t)
{
    process_helper(t,typename is_integral<T>::type());
}

int main()
{
    cout << Factorial<6>::value << endl;
    cout << get_min_value<10,20>::value << endl;
    If<true>::Fun();

    process(120);
    process(2.2);
    process(string("Test"));

    return 0;
}

