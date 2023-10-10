#include <iostream>
using namespace std;

// Sap xep bubbleSort tang dan
void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
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
    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}