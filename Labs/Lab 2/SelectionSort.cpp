// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 2: Complexity Analysis 

#include <cstdlib>
#include <vector>
#include <iostream>

template<typename T>
void swap( T& a, T& b )
{
    T temp = a;
    a = b;
    b = temp;
}

void selSort( std::vector<int>& v )
{
    for ( int i = 0; i < v.size(); i++ )
    {
        int smallest = v[i]; 
        int smallest_index = i;
        for ( int j = i; j < v.size(); j++ )
        {
           if ( v[j] < smallest )
           {
               smallest = v[j];
               smallest_index = j;
           } 
        }
        swap( v[i],v[smallest_index] );
    }
}

int main()
{
    clock_t start, finish;
    srand( time( nullptr ) );
    std::vector<int> v;
    int n = 0;

    std::cout << "Enter size of input: " << " "; 
    std::cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        v.push_back( rand() % 100 + 1 );
    }
    
    start = clock();
    selSort( v );
    finish = clock();

    // for ( int i = 0; i < v.size(); i++ )
    // {
    //     std::cout << v[i] << ' ';
    // }
    
    std::cout << "Time = " << finish - start << '\n';

    return 0;
}