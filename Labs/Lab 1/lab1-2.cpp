#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Stack
{
<<<<<<< HEAD
  public:
    Stack();
    void push(T data);
    void pop();
    T get_top();
    bool is_empty();

  private:
    std::vector<T> stack;
=======
public:
  Stack();
  void push(T data);
  void pop();
  T get_top();
  bool is_empty();
  int size() const;
  T get(int location) const;

private:
  std::vector<T> stack;
>>>>>>> 514617e58e634185ac57b9be1d7bad0db285676a
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
void Stack<T>::push(T data)
{
<<<<<<< HEAD
    stack.push_back(data);
=======
  stack.push_back(data);
>>>>>>> 514617e58e634185ac57b9be1d7bad0db285676a
}

template <typename T>
void Stack<T>::pop()
{
<<<<<<< HEAD
    stack.pop_back();
=======
  stack.pop_back();
>>>>>>> 514617e58e634185ac57b9be1d7bad0db285676a
}

template <typename T>
T Stack<T>::get_top()
{
<<<<<<< HEAD
    return stack.back();
=======
  return stack.back();
>>>>>>> 514617e58e634185ac57b9be1d7bad0db285676a
}

template <typename T>
bool Stack<T>::is_empty()
{
<<<<<<< HEAD
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
=======
  if (stack.size() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
int Stack<T>::size() const
{
  return stack.size();
}

template <typename T>
T Stack<T>::get(int location) const
{
  return stack[location];
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

// TODO: Finish this function
std::string infix_to_postfix(std::string x)
{
  Stack<char> s = Stack<char>();
  s.push('[');
  x.append("]");
  std::string y;
  int index = 0; // index to y

  while (!s.is_empty())
  {
    for (int i = 0; i < x.length(); i++)
    {
      s.push(x[i]);
      if (is_operator(x[i]))
      {
        y[i] = s.get_top();
>>>>>>> 514617e58e634185ac57b9be1d7bad0db285676a
        s.pop();
    }
<<<<<<< HEAD
    return y;
}

int main()
{
    std::string infix_expr1 = "(A+B)*C-(D/(J+D))";

    std::cout << infix_expr1 << " translates to: " << infix_to_postfix(infix_expr1) << '\n';
    return 0;
}
=======
  }
}

  int main()
  {
    Stack<int> s = Stack<int>();
    std::string test = "(A+B)*C";
    test.append("]");
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    for (int i = 0; i < s.size(); i++)
    {
      std::cout << s.get(i) << '\n';
    }

    std::cout << "Top of the stack is: " << s.get_top() << '\n';
    std::cout << test << '\n';
    return 0;
  }
>>>>>>> 514617e58e634185ac57b9be1d7bad0db285676a
