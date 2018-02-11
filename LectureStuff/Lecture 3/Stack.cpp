#include "Stack.h"
#include <vector>

template <typename T>
Stack<T>::Stack() {}

template <typename T>
void Stack<T>::push(T data) {
  stack.push_back(data);
}

template <typename T>
void Stack<T>::pop() {
  stack.pop_back();
}

template <typename T>
T Stack<T>::get_top() {
  return stack.back();
}

template <typename T>
bool Stack<T>::is_empty() {
  if (stack.size() == 0) {
    return true;
  } else {
    return false;
  }
}