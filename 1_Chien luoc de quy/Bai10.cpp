#include <iostream>
using namespace std;

/* Dinh nghia de quy tim so thu n trong day F: 1, 2, 5, 26, 677, 458330, ...
- Dinh nghia: So thu F(n) = |1 neu n == 1
                            |F(n-1)*F(n-1) + 1 voi n>1
*/

int F(int n)
{
    if (n == 1)
        return 1;
    else
        return F(n - 1) * F(n - 1) + 1;
}

// hien thi n so le dau tien cua day
void display_first_n_odd_numbers_in_F(int n)
{
    int count = 0, i = 0, max_num = 2 * n;
    while (count < n)
    {
        i++;
        int f_i = F(i);
        if (f_i % 2 == 1)
        {
            cout << f_i << " ";
            count++;
        }
        if (i >= max_num)
        {
            break;
        }
    }
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
    cout << "So thu " << n << " trong day F la: " << F(n) << endl;
    cout << n << " so le dau cua day la: ";
    display_first_n_odd_numbers_in_F(n);
}