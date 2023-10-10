#include <bits/stdc++.h>
using namespace std;

void insertionSort(string word[], int n)
{
    for (int i = 1; i < n; i++)
    {
        string t = word[i];
        int j = i - 1;
        while (j > -1 && word[j] > t)
        {
            word[j + 1] = word[j];
            j--;
        }
        word[j + 1] = t;
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

    insertionSort(word, n);
    cout << "\n--- DANH SACH TU DA NHAP ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << word[i] << " ";
    }
}