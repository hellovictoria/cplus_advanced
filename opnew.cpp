#include <iostream>
#include <stdio.h>

using namespace std;

void* operator new(size_t size){cout << "new "<<endl;}
void* operator new[](size_t size){cout << "new[] "<<endl;}


int main()
{
    int *a=new int[4];
    int *b=new int(4);
    int *c=new(int);
    return 0;
}
