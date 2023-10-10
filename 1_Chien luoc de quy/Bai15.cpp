#include <iostream>
using namespace std;

// De quy tinh P(n)=1x3x5x...x(2n+1)
/* Dinh nghia: P(n)=1 neu n==0
               P(n)=P(n-1)*(2*n+1) voi n>0
*/

int P(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return P(n - 1) * (2 * n + 1);
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    while (n < 0)
    {
        cout << "n = ";
        cin >> n;
    }

    cout << "P(" << n << ") = " << P(n);
}