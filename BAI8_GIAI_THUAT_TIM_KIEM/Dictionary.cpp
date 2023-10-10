#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int binarySeacrh(string x[], int left, int right, string word)
{
    if (left > right)
        return -1;
    else
    {
        int mid = (left + right) / 2;
        if (x[mid] == word)
            return mid;
        else if (x[mid] > word)
            return binarySeacrh(x, left, mid - 1, word);
        return binarySeacrh(x, mid + 1, right, word);
    }
}

void nhap(string x[], int &n)
{
    cout << "Nhap so luong tu: ";
    cin >> n;
    cout << "\n===== DANH SACH CAC TU ======\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Tu thu " << i + 1 << ": ";
        fflush(stdin);
        getline(cin, x[i]);
    }
}

void xuat(string x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
}

int main()
{

    int n;
    string x[100];
    string word;
    nhap(x, n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (x[j] < x[j - 1])
            {
                string tg = x[j];
                x[j] = x[j - 1];
                x[j - 1] = tg;
            }
        }
    }
    cout << "Danh sach tu da nhap\n";
    xuat(x, n);
    cout << endl
         << "Nhap tu can tim: ";
    fflush(stdin);
    getline(cin, word);
    // Tao loading...
    cout << "Loading";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        fflush(stdout); // flush stdout để in ra luôn, không chờ buffer
        sleep(1);       // tạm dừng 1 giây
    }
    int pos = binarySeacrh(x, 0, n - 1, word);
    if (pos == -1)
        cout << "\nKhong tim thay tu " << word << " trong tu dien";
    else
        cout << "\nTim thay tu " << word << " o vi tri " << pos + 1;
}