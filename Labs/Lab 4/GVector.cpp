// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 4: Vectors
// File: GVector.cpp

#include "GVector.h"
#include <iostream>

int main()
{
  srand(time(NULL));

  GVector<int> v = GVector<int>();

  for (int i = 0; i < 10; i++)
  {
    v.push_back(rand() % 100 + 1);
  }

  std::cout << "GVector v contains: ";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
  std::cout << "Size: " << v.size() << '\n';

  std::cout << "v.pop_back(): " << v[v.size() - 1] << '\n';
  v.pop_back();

  std::cout << "GVector v now contains: ";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
  std::cout << "Size: " << v.size() << '\n';

  std::cout << "Inserting 10 at index 3. " << '\n';
  v.insert(3, 10);

  std::cout << "GVector v now contains: ";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << ' ';
  }

  std::cout << '\n';
  std::cout << "Size: " << v.size() << '\n';

  std::cout << "Erasing 10 at index 3. " << '\n';
  v.erase(3);

  std::cout << "GVector v now contains: ";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << ' ';
  }

  std::cout << '\n';
  std::cout << "Size: " << v.size() << '\n';

  v.clear();
  if (v.size() == 0)
  {
    std::cout << "GVector v is now cleared. " << '\n';
  }
  std::cout << "Size: " << v.size() << '\n';
}