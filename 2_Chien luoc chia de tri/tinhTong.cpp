#include <bits/stdc++.h>
using namespace std;

int tong(int d[], int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == r)
        return d[l];
    else if (l == r - 1)
        return d[l] + d[r];
    else
    {
        int m = (l + r) / 2;
        return tong(d, l, m) + tong(d, m + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int *d = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    cout << tong(d, 0, n - 1);
}