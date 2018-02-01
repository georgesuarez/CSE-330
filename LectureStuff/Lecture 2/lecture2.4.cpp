#include <iostream>
#include <vector>

// Remove all elements in v of value x
void remove(std::vector<int> &v, int x) {
    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (*it == x) {
            v.erase(it);
            it--;
        }
    }
}

void display(std::vector<int> &v) {
    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " "; 
    }
    std::cout  << '\n';
}

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(10);

    display(v);

    remove(v, 10);

    display(v);

    return 0;
}