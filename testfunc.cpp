#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    plus<int> plus1;
    cout << "the result of plus(4,5)=" << plus1(4,5) << endl;
    vector<int> vec{1,2,3,4};
    //auto it=vec.begin();
    //while((it=find_if(it,vec.end(),[](int i){return i>=2;}))!=vec.end())
    //{
     //   cout << *it++ << endl;
    //}
    //cout <<*find_if(vec.begin(),vec.end(),[](int i){return i>=2;})<<endl;
    auto it = find_if(vec.begin(),vec.end(),[](int i){return i>=2;});
    while(it!=vec.end())
    {
     cout << *it++ <<endl;
    }
    return 0;
}
