#include <bits/stdc++.h>
using namespace std;

int pow(float a, int n)
{
    if (n == 1)
        return a;
    else
        return a * pow(a, n - 1);
}

int main()
{
    cout << pow(2, 7);
}