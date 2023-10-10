#include <iostream>
using namespace std;

// de quy doi sang nhi phan so nguyen duong n
// neu n==0 thi binary(n)=0
// neu n>0 thi binary(n)=binary(n/2)*10 + (n%2)
long binary(int n)
{
    if (n == 0)
        return 0;
    else
        return binary(n / 2) * 10 + (n % 2);
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
    cout << binary(n);
}