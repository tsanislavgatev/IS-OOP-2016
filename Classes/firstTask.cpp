#include <iostream>

using namespace std;

class fib{
    private:
        int* arry;
        int sizeOfArray;

    public:
        fib(int n)
        {
            arry = new int[n];
            sizeOfArray = n;
            fibunacci();
        }
        ~fib()
        {
            delete[] arry;
        }

    private:
        void fibunacci();

    public:
        int getElement(int index);
};

void fib::fibunacci()
{
    arry[0] = 1;
    arry[1] = 1;
    for(int i = 2; i < sizeOfArray; i++)
    {
        arry[i] = arry[i - 1] + arry[i - 2];
    }
}

int fib::getElement(int index)
{
    if(index < 0 && index > sizeOfArray)
    {
        return false;
    }
    else
    {
        return arry[index];
    }
}

int main()
{
    fib test(10);

    std::cout << test.getElement(9) << std::endl;


    return 0;
}
