#include <iostream>
using namespace std;

// Sap xep chen giam dan
void insertionSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmpElement = a[i];
        int j = i - 1;
        while (j > -1 && tmpElement > a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmpElement;
    }
}

int main(int argc, char const *argv[])
{
    int *a, n;
    cout << "n=";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "]=";
        cin >> *(a + i);
    }
    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}
