#include<algorithm>
#include<numeric>
#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

typedef vector<int> int_vector;
typedef istream_iterator<int> istream_itr;
typedef ostream_iterator<int> ostream_itr;
typedef back_insert_iterator<int_vector> back_ins_itr;

int main()
{
    /*vector<int> vec(10);
    //void iota( ForwardIterator first, ForwardIterator last, T value );.Fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value. 
    iota(vec.begin(),vec.end(),2);

    copy(vec.cbegin(),vec.cend(),ostream_iterator<int>(cout," "));
    cout << endl;

    cout << "Entrer Ctrl+D, get sum.\n";
    istream_iterator<int> numbersIter(cin);
    istream_iterator<int> endIter;
    int sum=accumulate(numbersIter,endIter,0);
    cout << "Sum: " << sum << endl;
*/
    int_vector vec;
    copy(istream_itr(cin),istream_itr(),back_ins_itr(vec));
    copy(vec.begin(),vec.end(),ostream_itr(cout,"\n"));
    sort(vec.begin(),vec.end());

    copy(vec.begin(),vec.end(),ostream_itr(cout,"\n"));

    return 0;
}
