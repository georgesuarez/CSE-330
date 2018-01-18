#ifndef STACK_H
#define STACK_H

#include <vector>

template<typename T>
class Stack {
public:
    Stack();
    void push(T data);
    void pop();
    T get_top();
    bool is_empty();
private: 
    std::vector<T> stack;
};

#endif // !STACK_H
