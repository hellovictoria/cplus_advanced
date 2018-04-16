#include "tempClassAdefine.hpp"
#include <iostream>

template<typename T>
A<T>::A(){}

template<typename T>
A<T>::~A(){}

template<typename T>
void A<T>::fun(int x,const T& y){std::cout << x+y<< std::endl;}

template<typename T>
T& A<T>::get(){}

