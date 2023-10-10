#include <iostream>
#include <math.h>
using namespace std;


// Neu n<10 thi tra ve 1
// neu n>=10 tra ve so luong chu so tuong ung
int count_digits(int n)
{
    if (n < 10)
    {
        return 1;
    }
    else
    {
        return 1 + count_digits(n/10);
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    while (n <= 0)
    {
        cout << "n = ";
        cin >> n;
    }
    cout << "So chu so cua " << n << " la: " << count_digits(n);
}