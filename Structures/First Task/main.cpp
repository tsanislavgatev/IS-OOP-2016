#include <iostream>
#include <cmath>

using namespace std;

struct rectangle{
    size_t a;
    size_t b;

};

void init(rectangle &forInit, size_t a, size_t b)
{
    forInit.a = a;
    forInit.b = b;
}

void print(rectangle &forPrint)
{
    cout << forPrint.a;
    cout << forPrint.b;
}

int s(rectangle &forCalculation)
{
    int s = forCalculation.a * forCalculation.b;

    return s;
}

int p(rectangle &forCalculation)
{
    int p = 2 * forCalculation.a + 2 * forCalculation.b;

    return p;
}

double d(rectangle &rect)
{
    double d = sqrt(rect.a * rect.a + rect.b * rect.b);

    return d;
}

int main()
{
    rectangle newOne;

    size_t a = 0;
    size_t b = 0;

    cin >> a;
    cin >> b;

    init(newOne,a,b);
    print(newOne);
    cout << s(newOne) << endl;
    cout << p(newOne) << endl;
    cout << d(newOne) << endl;

    return 0;
}
