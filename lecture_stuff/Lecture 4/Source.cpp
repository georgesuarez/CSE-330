#include <string>
#include <iostream>
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

template<typename T>
Stack<T>::Stack() {}

template<typename T>
void Stack<T>::push(T data) {
    stack.push_back(data);
}

template<typename T>
void Stack<T>::pop() {
    stack.pop_back();
}

template<typename T>
T Stack<T>::get_top() {
    return stack.back();
}

template<typename T>
bool Stack<T>::is_empty() {
    if (stack.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}



int main()
{
    Stack<char> stack = Stack<char>();
    std::string x = "A+B-C/(A*B)]";
    int index = 0;

    char s = x[index];

    while (s != ']')
    {
        // Process s



        ++index;
        s = x[index];
    }

}