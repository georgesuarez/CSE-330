#include <iostream>

long fact(int n)
{
    if ( n == 0 || n == 1 )
    {
        return 1;
    }
    else
    {
        return n * ( n - 1 );
    }
}

int main()
{
    int n = 0;
    std::cout << "Enter n: " << '\n';
    std::cin >> n;

    long answer = fact(n);

    std::cout << n << "! = " << answer << '\n';
    
    return 0;
}
