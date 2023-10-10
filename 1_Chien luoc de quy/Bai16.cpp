#include <iostream>
using namespace std;

// De quy tinh S(n) = 1 + 1.2 + 1.2.3 + ... + 1.2.3.....n voi n>0
// neu n==1 thi S(n)=1
// neu n>1 thi S(n)=S(n-1)+factorial(n)
int S(int n)
{
    if (n == 1)
        return 1;
    else
    {
        int tinh=1;
        for (int i=2; i<=n; i++)
            tinh *= i;     
        return S(n - 1) + tinh;
    }
}

int main()
{
    cout << S(4);
}