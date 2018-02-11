#include <iostream>
#include <vector>

template <typename T>
class MyQueue {
 public:
  MyQueue();
  void Add(T x);
  void Remove();
  void Print();
  T Find(int i);   // Returns q[i]
  int FindI(T x);  // Returns index
 private:
  std::vector<T> q;
};

template <typename T>
MyQueue<T>::MyQueue() {}

template <typename T>
void MyQueue<T>::Add(T x) {
  q.push_back(x);
}

template <typename T>
void MyQueue<T>::Remove() {
  q.erase(q.begin());
}

template <typename T>
void MyQueue<T>::Print() {
  if (q.size() == 0) {
    return;
  }

  typename std::vector<T>::iterator it;
  for (it = q.begin(); it != q.end(); ++it) {
    std::cout << *it << '\n';
  }
}

template <typename T>
int MyQueue<T>::FindI(T x) {
  for (int i = 0; i < q.size(); i++) {
    if (q[i] == x) {
      return i;
    }
  }

  return -1;  // Not found
}

template <typename T>
T MyQueue<T>::Find(int i) {
  return q[i];
}

int main() {
  MyQueue<int> queue = MyQueue<int>();

  queue.Add(10);
  queue.Add(20);
  queue.Add(30);
  queue.Add(40);

  queue.Print();

  std::cout << queue.FindI(0) << '\n';
  return 0;
}