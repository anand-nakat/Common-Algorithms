#include <iostream>
using namespace std;

void getInput(int a[], int n);
void printArray(int a[], int);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) //n-1 passes
    {
        for (int j = 0; j < n - i; j++) //(n-i)th place fixed after each pass
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}
int main()
{
    int n;
    cout << "Enter no of elements in Array:";
    cin >> n;
    int a[n];
    getInput(a, n);
    cout << "\nArray before sorting:";
    printArray(a, n);
    bubbleSort(a, n);
    cout << "\nArray after sorting:";
    printArray(a, n);
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
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}