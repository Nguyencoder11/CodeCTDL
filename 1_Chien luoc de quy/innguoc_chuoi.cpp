#include <bits\stdc++.h>
using namespace std;
void print(char *str)
{
    *str && (print(str + 1), cout << *str);
}
int main()
{
    char str[255];
    cout << "Nhap chuoi: ";
    gets(str);
    cout << "Chuoi dao nguoc la: ";
    print(str);
    return 0;
}
void inNguoc(const char *str, int i)
{
    if (str[i] == '\0')
        return;
    else
    {
        inNguoc(str, i + 1);
        cout << str[i];
    }
}
int main(int argc, char const *argv[])
{
    inNguoc("lan anh", 0);
}


