#include <iostream>
#include <string>
#include "Stack.h"

int main() {
  Stack<double> s = Stack<double>();

  s.push(3.14);
  s.pop();

  return 0;
}