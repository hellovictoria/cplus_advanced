#include <list>
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

