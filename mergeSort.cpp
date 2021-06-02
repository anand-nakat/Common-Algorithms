#include <iostream>
using namespace std;

void getInput(int a[], int);
void printArray(int a[], int n);
void mergeSort(int a[], int, int);
void merge(int a[], int, int, int, int);
int main()
{
    int n;
    cout << "Enter the size of Array:\n";
    cin >> n;
    int array[n];
    getInput(array, n);
    printArray(array, n);
    mergeSort(array, 0, n - 1);
    cout << "After sorting:\n";
    printArray(array, n);
    return 0;
}

void mergeSort(int a[], int i, int j)
{
    //Small Problem
    if (i == j)
        return;
    //Big Problem
    int mid = (i + j) / 2;
    mergeSort(a, i, mid);
    mergeSort(a, mid + 1, j);
    merge(a, i, mid, mid + 1, j);
}

void merge(int a[], int low, int mid, int k, int high)
{
    int l = 0, m = high - low + 1, i, j;
    i = low;
    j = high;

    int b[m];
    while (i <= mid && k <= j)
    {
        if (a[i] < a[k])
            b[l++] = a[i++];
        else
            b[l++] = a[k++];
    }
    while (i <= mid)
        b[l++] = a[i++];

    while (k <= j)
        b[l++] = a[k++];

    //Copy back elements to array a
    for (int i = low, j = 0; j < m; i++, j++)
        a[i] = b[j];
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