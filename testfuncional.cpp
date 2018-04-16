#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

class Nth
{
    public:
        Nth(int n=0):nth_(n),count_(0){}
        bool operator() (int val)
        {
            if(val==nth_)
            {
                cout << count_ <<endl;
                count_++;
                return true;
            }
            return false;
        }

        unsigned int getCount() const
        {
            return count_;
        }

    private:
    int nth_;
    unsigned int count_;
};

int main()
{
    Nth nth(3);
    vector<int> vec{1,2,3,4,5,6,7,8,9,10,3};
    auto it=vec.begin();
    
    while((it=find_if(it,vec.end(),ref(nth)))!=vec.end())
    {
       cout << "3rd:" << *it << endl;
       it++;
    }
    cout << "State:" <<nth.getCount() << endl;
    cout << endl;
    return 0;
}

