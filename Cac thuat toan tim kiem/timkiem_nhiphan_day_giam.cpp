#include <iostream>
using namespace std;

// Tim kien nhi phan theo day giam dan
int binarySeacrh(int x[], int left, int right, int key)
{
    if (left > right)
        return -1;
    else
    {
        int mid = (left + right) / 2;
        if (x[mid] == key)
            return mid;
        else if (x[mid] > key)
            return binarySeacrh(x, mid + 1, right, key);
        return binarySeacrh(x, left, mid - 1, key);
    }
}

int main(int argc, char const *argv[])
{
    int x[100], n, key;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> x[i];
    }
    cout << "key = ";
    cin >> key;
    cout << binarySeacrh(x, 0, n - 1, key);
}
