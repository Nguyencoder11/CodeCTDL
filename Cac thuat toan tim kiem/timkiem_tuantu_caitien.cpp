#include <iostream>
using namespace std;

int tktt_ct(int x[], int n, int k)
{
    int i = 0;
    x[n] = k;
    while (x[i] != k)
    {
        i++;
    }
    if (i < n)
        return i;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    int x[100], n, k;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> x[i];
    }
    cout << "k = ";
    cin >> k;
    cout << tktt_ct(x, n, k);
}
