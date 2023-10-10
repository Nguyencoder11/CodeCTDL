#include <iostream>
using namespace std;

// giai thuat de quy tinh tong cac phan tu trong mang so nguyen a
int sum_arr(int a[100], int n)
{
    // Mang co mot phan tu thi tra ve a[0]
    if (n == 1)
        return a[0];
    else
        return a[n - 1] + sum_arr(a, n - 1);
}

int main()
{
    int a[100], n;
    cout << "n = ";
    cin >> n;
    cout << "input array elements:";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << sum_arr(a, n);
}