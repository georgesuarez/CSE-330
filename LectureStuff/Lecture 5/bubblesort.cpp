#include <ctime>
#include <iostream>
#include <vector>

// Quiz: Create a swap function that works with any data type.
template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

std::vector<int> bubble_sort(std::vector<int> v) {
  int n = v.size();                // 1
  for (int i = n - 1; i > 0; i--)  // n - 1
  {
    for (int j = 0; j < i; j++)  // (n^2 - n)/ 2
    {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }

  return v;
}

// Quiz: Give O, Omega, and Theta functions

// Big-O
// T(n) = 3(n^2 - n) / 2 + n - 1 + 1
// T(n) = 3/2(n^2) - 3n/2 + n
// T(n) = 3/2(n^2) - 1/2(n) + 1
// T(n) = O(n^3) < cn^3 for n >= n_0
//
//
// T(n) = O(n^2)
// T(n) = 3/2(n^2) - 1/2(n) + 1 <= cn^2 for n > n_0
//
// Omega
// 3/2(n^2) - 1/2(n) + 1 >= cn^2 for n >= n_0
// 3/2(n^2) - 1/2(n) + 1 >= (1)n^2 for n >= 1
// omega(n^2)
//
// T(n) = 3/2(n^2) - 1/2(n) + 1
// lim          3/2(n^2) - 1/2(n) + 1 / (n^2) = 3/2

int main() {
  std::vector<int> data;
  srand(time(nullptr));

  for (int i = 0; i < 10; i++) {
    int random_data = rand() % 100 + 1;
    data.push_back(random_data);
  }

  std::cout << "Sorting random data..." << '\n';
  std::vector<int> sorted = bubble_sort(data);
  std::cout << "Sorting complete." << '\n';

  std::cout << "Result: ";
  for (int i = 0; i < sorted.size(); i++) {
    std::cout << sorted[i] << " ";
  }

  std::cout << '\n';

  // char x_1 = 'x';
  // char y_1 = 'y';

  // swap( x_1,y_1 );

  // std::cout << x_1 << '\n';
  // std::cout << y_1 << '\n';

  return 0;
}