#include <iostream>
#include <stack>
#include <string>

int main() {

    std::string test_expression = "(A+B)*C(D/(J/D))";

    std::stack<char> infix;
    for (int i = 0; i < test_expression.length(); i++) {
        // Do stuff here....
    }
    return 0;
}