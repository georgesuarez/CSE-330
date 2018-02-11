// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 2: Complexity Analysis
// File: BubbleSort.cpp

#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

void bubbleSort(std::vector<int> &v) {
  int n = v.size();
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

int main() {
  clock_t start, finish;
  srand(time(nullptr));
  std::vector<int> v;
  int n = 0;

  std::cout << "Enter size of input: ";
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    v.push_back(rand());
  }

  start = clock();
  bubbleSort(v);
  finish = clock();

  std::cout << "Time = " << finish - start << '\n';

  return 0;
}