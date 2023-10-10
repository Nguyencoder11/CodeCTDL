#include <iostream>
using namespace std;

/* Dinh nghia de quy:
- f(m, n) = |m+1 neu n<=0
            |n+1 neu m<=0
            |f(m-1, n)+f(m, n-1) cac truong hop con lai
*/

// Giải thuật
int f(int m, int n)
{
    if (n <= 0)
        return (m + 1);
    else if (m <= 0)
        return (n + 1);
    else
        return f(m - 1, n) + f(m, n - 1);
}

int main()
{
    // Tính giá trị của f(1, 3)
    cout << f(1, 3);
}