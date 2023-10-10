#include <bits/stdc++.h>
using namespace std;

void selectionSort(string word[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (word[j] < word[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            string tg = word[m];
            word[m] = word[i];
            word[i] = tg;
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong tu: ";
    cin >> n;
    string word[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Tu thu " << i + 1 << ": ";
        fflush(stdin);
        getline(cin, word[i]);
    }

    selectionSort(word, n);
    cout << "\n--- DANH SACH TU DA NHAP ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << word[i] << " ";
    }
}