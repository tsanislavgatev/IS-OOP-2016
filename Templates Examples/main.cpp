#include <iostream>
#include "Example.h"
#include <cstdlib>

template <typename T>
T minOfTwo(T first, T second)
{
    if(first < second)
    {
        return first;
    }
    return second;

}


int main()
{
    Example<int> example;
    int* arrayOfInts = new int[10];
    Example<double> exampleDouble;
    double* arrayOfDoubles = new double[10];
    double delIndex = 7.1;

    for(int i = 0; i < 10; i++)
    {
        arrayOfInts[i] = rand() % 100;
        std::cout << arrayOfInts[i] << std::endl;
        arrayOfDoubles[i] = double(arrayOfInts[i])/delIndex ;
        std::cout << arrayOfDoubles[i] << std::endl;
    }

    example.sortInsertion(arrayOfInts,10);
    exampleDouble.sortInsertion(arrayOfDoubles,10);

    std::cout << "________________________________" << std::endl;

    for(int i = 0; i < 10; i++)
    {
        std::cout << arrayOfInts[i] << std::endl;
    }

    std::cout << "________________________________" << std::endl;

    for(int i = 0; i < 10; i++)
    {
        std::cout << arrayOfDoubles[i] << std::endl;
    }

    return 0;
}
