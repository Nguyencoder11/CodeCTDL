#include <bits/stdc++.h>
using namespace std;

void sapxep_giam(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            int tg = a[i];
            a[i] = a[m];
            a[m] = tg;
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