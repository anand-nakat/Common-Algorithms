#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

void getInput(int a[], int);
void printArray(int a[], int n);

std::pair<int, int> minMax(int a[], int low, int high)
{
    std::pair<int, int> ans, leftAns, rightAns;
    if (low == high)
    {
        ans.first = a[low];
        ans.second = a[low];
        return ans;
    }
    if (high == low + 1)
    {
        ans.first = min(a[low], a[high]);
        ans.second = max(a[low], a[high]);
        return ans;
    }
    else
    {
        int mid = (low + high) / 2;
        leftAns = minMax(a, low, mid);
        rightAns = minMax(a, mid + 1, high);
        ans.first = min(leftAns.first, rightAns.first);
        ans.second = max(leftAns.second, rightAns.second);
        return ans;
    }
}

int main()
{
    int n;
    cout << "Enter no of Elements:";
    cin >> n;
    int a[n];
    getInput(a, n);
    printArray(a, n);
    std::pair<int, int> ans = minMax(a, 0, n - 1);
    cout << "Min Element:" << ans.first << "\nMax Element:" << ans.second;
}

void getInput(int a[], int n)
{
    cout << "\nEnter elements of array:\n";
    int temp, i = 0;
    while (n--)
    {
        cin >> temp;
        a[i++] = temp;
    }
}

void printArray(int a[], int n)
{
    cout << "Elements of Array are:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}