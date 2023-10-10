#include <bits/stdc++.h>
using namespace std;

void bubbleSort(string word[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (word[j] < word[j - 1])
            {
                string tg = word[j];
                word[j] = word[j - 1];
                word[j - 1] = tg;
            }
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

    bubbleSort(word, n);
    cout << "\n--- DANH SACH TU DA NHAP ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << word[i] << " ";
    }
}