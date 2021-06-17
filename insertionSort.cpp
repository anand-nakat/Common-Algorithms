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
void insertionSort(int a[], int n)
{
    int i, j, k;
    for (int i = 0; i < n - 1; i++)
    {
        j = i + 1;
        k = i;
        while (a[j] < a[k])
        {
            swap(&a[j], &a[k]);
            k--;
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
    insertionSort(a, n);
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