#include <bits/stdc++.h>
using namespace std;

void sapxep_giam(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int t = a[i];
        int j = i - 1;
        while (j > -1 && t > a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
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