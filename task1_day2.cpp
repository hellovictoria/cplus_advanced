#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>

using namespace std;

double MultipliesOfTwoNumber(int fst,int sec)
{
    return fst*sec;
}

double GeometricMeanOfCallBackWay(const vector<int>& nums)
{
    double mult=accumulate(nums.cbegin(),nums.cend(),1,MultipliesOfTwoNumber);
    cout << mult << endl;
    return pow(mult,1.0/nums.size());
}

double GeometricMeanOfLambdaWay(const vector<int>& nums)
{
    double mult = accumulate(nums.cbegin(),nums.cend(),1,[](int fst,int sec){return fst*sec;});
    return pow(mult,1.0/nums.size());
}

double GeometricMeanofFunctor(const vector<int>& nums)
{
    double mult=accumulate(nums.cbegin(),nums.cend(),1,multiplies<int>());
    return pow(mult,1.0/nums.size());
}


double GeometricMeanofTransparentFunctor(const vector<int>& nums)
{
    double mult=accumulate(nums.cbegin(),nums.cend(),1,multiplies<>());
    return pow(mult,1.0/nums.size());
}

int main()
{
    vector<int> v{1,2,3,4};
    cout << "CallBack: " << GeometricMeanOfCallBackWay(v)<< endl;
    cout << "Lambda: " << GeometricMeanOfLambdaWay(v) << endl;
    cout << "Functor: " << GeometricMeanofFunctor(v) << endl;
    cout << "TransparentFunctor: " << GeometricMeanofTransparentFunctor(v) << endl;
    return 0;
}
