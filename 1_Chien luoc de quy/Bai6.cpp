#include <iostream>
using namespace std;

// De quy tim so thu n trong day F: 4, 3, -2, -6, -5, 0, 4,...
int F(int n)
{
    if (n == 1)
        return 4;
    if (n == 2)
        return 3;
    return F(n - 1) - F(n - 2) - 1;
}

int main()
{
    cout << F(4);
}