#include <iostream>

using namespace std;

struct SJob
{
    char name[40];
    double salary;
};


struct stru
{
    int i;
    char c;
};

template<class T>
void Swap_nolen(T *a,T *b)
{
    T temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

template void Swap_nolen<int>(int*,int*);

template void Swap_nolen<stru>(stru*,stru*);

template void Swap_nolen<const char*>(const char**,const char**); 

template<class T>
void Swap(T *a,T *b,int len=10)
{
    cout << "==============call base function template================" << endl;
    T temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
/*
void Swap1(const char** first,const char** second,int len)
{
    char* temp;
    for(int i=0;i<len;i++)
    {
        cout << *first <<","<< *second << endl;
        temp=first;
        first=second;
        second=temp;
        first++;
        second++;
    }
}*/

void Swap(const char** first,const char** second,int len)
{
    cout << "======non template======="<< endl;
    std::swap(*first,*second);
    std::swap(*(first+1),*(second+1));
    cout << len << endl;
}

template<>
void Swap<const char*>(const char** first,const char** second,int len)  // te hua
{
    cout << "======te hua======="<< endl;
    std::swap(*first,*second);
    std::swap(*(first+1),*(second+1));
    cout << len << endl;
}

int main()
{
    int a=10;
    int b=20;
    cout << "a=" << a << ",b=" << b <<endl;
    Swap_nolen(&a,&b);
    cout << "a=" << a << ",b=" << b <<endl;

    stru stru1,stru2;
    stru1.i=1;
    stru1.c='a';
    stru2.i=2;
    stru2.c='b';
    Swap_nolen(&stru1,&stru2);
    cout << "stru1.i=" << stru1.i << ",stru1.c="<< stru1.c << endl;
    cout << "stru2.i=" << stru2.i << ",stru2.c="<< stru2.c << endl;

    const char* firstArray[] = {"one","two"};
    const char* secondArray[] = {"three","four"};
    Swap_nolen(firstArray,secondArray);
    cout << "firtArray[0]= " << *firstArray << ",firstArray[1]= " << *(firstArray+1) << endl;
    cout << "SecArray[0]= " << *secondArray << ",SecArray[1]= " << *(secondArray+1) << endl;


    SJob sj1{"Mike",9000};
    SJob sj2{"Anne",10000};
    cout << sj1.name << "," << sj1.salary << endl;
    cout << sj2.name << "," << sj2.salary << endl;
    Swap(&sj1,&sj2);
    cout << sj1.name << "," << sj1.salary << endl;
    cout << sj2.name << "," << sj2.salary << endl;


    const char* astr1[]={"hello","world"};
    const char* astr2[]={"world","hello"};
//    Swap1(astr1,astr2,2);
    cout << *astr1 << "," << *(astr1+1) << endl;
    cout << *astr2 << "," << *(astr2+1) << endl;
    Swap<const char*>(astr1,astr2);
    //Swap(astr1,astr2);
    //Swap(astr1,astr2,10);
    cout << *astr1 << "," << *(astr1+1) << endl;
    cout << *astr2 << "," << *(astr2+1) << endl;
    return 0;
}


