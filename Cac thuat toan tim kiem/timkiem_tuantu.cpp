#include <iostream>
using namespace std;

int tktt(int x[], int n, int k)
{
    int i = 0;
    while (i < n && x[i] != k)
    { // Khi phan tu tai vi tri i<n khac k thi tiep tuc kiem tra phan tu ke tiep
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
    cout << tktt(x, n, k);
}
