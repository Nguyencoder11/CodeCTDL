#include <bits/stdc++.h>
using namespace std;

void sapxep_giam(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] > a[j - 1])
            {
                int tg = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tg;
            }
        }
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sapxep_giam(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}