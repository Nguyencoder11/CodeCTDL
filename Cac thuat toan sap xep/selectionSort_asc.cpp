#include <iostream>
using namespace std;

// Sap xep lua chon tang dan
void selectionSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        // Vong lap tim vi tri phan tu co gia tri min
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        // Dao vi tri 2 phan tu dau tien va ptu co min_index
        if (min_index != i)
        {
            int t = a[min_index];
            a[min_index] = a[i];
            a[i] = t;
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
    selectionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}
