#include <iostream>
using namespace std;

int powerOfElement(int a, int n)
{
    int mid;
    if (n == 1)
        return a;
    else
        mid = n / 2;
    int b = powerOfElement(a, mid);
    int c = b * b;
    if (n % 2 == 0)
        return c;
    return c * a;
}

int main()
{
    int a, n;
    cout << "Enter number(base):";
    cin >> a;
    cout << "Enter power:";
    cin >> n;
    cout << a << "^" << n << ":" << powerOfElement(a, n);
}
