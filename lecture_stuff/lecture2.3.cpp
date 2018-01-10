#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int value = 10;

    for (int i = 0; i < 6; i++) {
        v.push_back(value);
        value += 10;
    }

    std::vector<int>::iterator it;
    it = v.begin(); // Pointing to the first element

    std::cout << *it << '\n';

    it++; // Moves the iterator up one
    it--; // Moves the iterator down one

    v.insert(it, 10); // Inserts the value 10 where it is pointing at
                      // then the pos of the iterator moves up one

    v.insert(v.end(), 10); // == v.push_back(10);

    return 0;
}