#include <iostream>
#include <vector>
#include <string>


int main() {
    std::vector<std::string> s; // Creates a vector of type string
                                // Vector is stack!
    s.push_back("Hello"); // Adds the element at the end of the vector
    s.pop_back(); // Removes the last object

    if (s.size() > 0) {
        s.pop_back();
    }

    s.clear(); // Clears the vector!

    // Process vector
    for (int i = 0; i < s.size(); i++) {
        std::cout << s[i] << '\n';
    }

    return 0;
}