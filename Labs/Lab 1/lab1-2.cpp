#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Stack
{
  public:
    Stack();
    void push(T data);
    void pop();
    T get_top();
    bool is_empty();

  private:
    std::vector<T> stack;
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
void Stack<T>::push(T data)
{
    stack.push_back(data);
}

template <typename T>
void Stack<T>::pop()
{
    stack.pop_back();
}

template <typename T>
T Stack<T>::get_top()
{
    return stack.back();
}

template <typename T>
bool Stack<T>::is_empty()
{
    if (stack.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_operand(char x)
{
    if (x >= '0' && x <= '9')
    {
        return true;
    }
    if (x >= 'a' && x <= 'z')
    {
        return true;
    }
    if (x >= 'A' && x <= 'Z')
    {
        return true;
    }

    return false;
}

bool is_operator(char x)
{
    if (x == '*' || x == '/' || x == '+' || x == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int prec(char x)
{
    int weight;
    switch (x)
    {
        case '*':
        case '/':
            weight = 2;
            break;
        case '+':
        case '-':
            weight = 1;
            break;
        default:
            weight = 0;
            break;
    }

    return weight;
}

std::string infix_to_postfix(std::string x)
{
    Stack<char> s = Stack<char>();
    std::string y;
    int index = 0; 

    while (x.length() > index)
    {
        if (is_operand(x[index]))
        {
            y += x[index];
        }
        else
        {
            if (x[index] == '(')
            {
                s.push(x[index]);
            }
            else if (x[index] == ')')
            {
                while (!s.is_empty() && s.get_top() != '(')
                {
                    y += s.get_top();
                    s.pop();
                }

                if (!s.is_empty())
                {
                    s.pop();
                }
                else
                {
                    return "Error: No matching '('\n";
                }
            }
            else if (is_operator(x[index]))
            {
                if (s.is_empty() || prec(s.get_top()) < prec(x[index]))
                {
                    s.push(x[index]);
                }
                else
                {
                    while (!s.is_empty() && prec(s.get_top()) >= prec(x[index]))
                    {
                        y += s.get_top();
                        s.pop();
                    }
                    s.push(x[index]);
                }
            }
            else
            {
                return "Error: Invalid input.\n";
            }
        }

        index++;
    }
    while (!s.is_empty())
    {
        y += s.get_top();
        s.pop();
    }
    return y;
}


int main()
{
    std::string infix_expr1 = "(A+B)*C-(D/(J+D))";

    std::cout << infix_expr1 << " translates to: " << infix_to_postfix(infix_expr1) << '\n';
    return 0;
}
