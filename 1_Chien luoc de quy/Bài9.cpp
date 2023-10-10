#include <iostream>
using namespace std;

/* De quy tim so thu n trong day F: 1, 1, 3, 5, 11, 21, 43, ...
- Dinh nghia: So thu F(n) = |1 voi n==1 hoac n==2
                            |F(n-1)+F(n-2)*2 voi n>2
*/

int F(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return F(n - 1) + 2 * F(n - 2);
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    while (n < 1)
    {
        cout << "n = ";
        cin >> n;
    }
    cout << "So thu " << n << " trong day F la: " << F(n);
}
