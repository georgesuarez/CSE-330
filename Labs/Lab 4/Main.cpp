#include <iostream>
#include "Mvector.h"

int main() {
  srand(time(nullptr));
  int n = 0;
  std::cout << "Enter a size n: " << '\n';
  std::cout << "> ";
  std::cin >> n;

  Mvector<int> v = Mvector<int>();

  for (int i = 0; i < n; ++i) {
    v.push_back(rand() % 100 + 1);
  }

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << '\n';
  }

  v.insert(0, 10);

  std::cout << v[0] << '\n';

  // v.erase(0);
  // std::cout << v[0] << '\n';

  return 0;
}