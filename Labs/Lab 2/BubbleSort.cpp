#include <vector>
#include <cstdlib>
#include <iostream>

template<typename T>
void swap( T& a,T& b )
{
    T temp = a;
    a = b;
    b = temp;
}

void bubbleSort( std::vector<int>& v )
{
    for ( int i = 0; i < v.size(); i++ )
    {
        for ( int j = i + 1; j < v.size(); j++ )
        {
            if ( v[j] > v[j + 1] )
            {
                swap( v[j], v[j + 1] );
            }
        }
    }
}

int main()
{
    clock_t start, finish;
    srand( time( nullptr ) );
    std::vector<int> v;
    int n = 0;

    std::cout << "Enter size of input: " << ' ';
    std::cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        v.push_back( rand() );
    }

    start = clock();
    bubbleSort( v );
    finish = clock();

    std::cout << "Time = " << finish - start << '\n';

    return 0;
}