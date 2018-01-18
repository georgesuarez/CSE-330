#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Stack {
public:
    Stack();
    void push(T data);
    void pop();
    T get_top();
    bool is_empty();
    int size() const;
    T get(int location) const;
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

template<typename T>
int Stack<T>::size() const {
    return stack.size();
}

template<typename T>
T Stack<T>::get(int location) const {
    return stack[location];
}



// TODO: Finish this function
std::string infix_to_postfix(std::string x) {
    Stack<char> s = Stack<char>();
    s.push('[');
    std::string y;
    int index = 0; // index to y

    while (s.get(index) != ']') {
        if (s.get(index) == '(') {
            if (s.get(index) == '*' || s.get(index) == '/') {
                while (s.get_top() == '*') {
                    // do something...
                }
            }
        }
    }
    return y; 
}

int main() {

    Stack<int> s = Stack<int>();

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    for (int i = 0; i < s.size(); i++) {
        std::cout << s.get(i) << '\n';
    }
    
    return 0;
}