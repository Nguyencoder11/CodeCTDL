#include <iostream>
using namespace std;

// de quy dem so lan xuat hien cua x trong mang a gom n phan tu
// neu n==0 thi tra ve 0 (mang rong)
// neu phan tu cuoi cung bang x tang bien dem len 1
// giam kich thuoc mang di 1 va lap lai cac buoc 1->3 cho cac mang con

int count_appear(int *a, int n, int x)
{
    if (n == 0)
        return 0;
    else if (a[n - 1] == x)
        return 1 + count_appear(a, n - 1, x);
    else
        return count_appear(a, n - 1, x);
}

int main()
{
    int *a, n;
    int x;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    cout << count_appear(a, n, x);
}