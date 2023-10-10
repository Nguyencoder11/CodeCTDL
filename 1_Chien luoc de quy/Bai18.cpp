#include <iostream>
using namespace std;

// De quy tinh S(n) = 1^2 + 2^2 + 3^2 +....+ n^2 voi n>0
int S(int n)
{
    if (n == 1)
        return 1;
    else
        return S(n - 1) + n * n;
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
    cout << S(n);
}