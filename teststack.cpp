#include<list>
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Stack
{
    public:
        Stack()=default;
        ~Stack(){};
        void push(T val);
        T pop();
        size_t size() const;
    private:
        list<T> list_;
        size_t stackSize_;
};

template<typename T>
void Stack<T>::push(T val)
{
    list_.push_back(val);
}

template<typename T>
T Stack<T>::pop()
{
    T val=list_.back();
    list_.pop_back();
    return val;
}

template<typename T>
size_t Stack<T>::size() const
{
    return list_.size();
}

template<>
class Stack<int>
{
    public:
        Stack()=default;
        ~Stack(){};
        void push(int val);
        int pop();
        size_t size() const;
    private:
        list<int> list_;
        size_t stackSize_;
};

void Stack<int>::push(int val)
{
    list_.push_back(val);
}

int Stack<int>::pop()
{
    int val=list_.back();
    list_.pop_back();
    return val;
}

size_t Stack<int>::size() const
{
    return list_.size();
}


int main()
{
    Stack<string> strStack;
    strStack.push("hello");
    strStack.push("world");
    cout << strStack.pop() << endl;
    cout << strStack.pop() << endl;

    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    cout << intStack.pop() << endl;
    cout << intStack.pop() << endl;
    return 0;
}
