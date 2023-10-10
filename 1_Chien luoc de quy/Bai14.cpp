#include <iostream>
#include <math.h>
using namespace std;

void nhap(int &x)
{
    cin >> x;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int m, y;
    cout << "m = ";
    nhap(m);
    cout << "y = ";
    nhap(y);
    cout << "P = " << factorial(m + y);
}