#include <iostream>
using namespace std;

void getInput(int a[], int);
void printArray(int a[], int);
int partition(int a[], int, int, int);
void quickSort(int a[], int, int);
void swap(int *, int *);
int main()
{

    int n;
    cout << "Enter the size of Array:\n";
    cin >> n;
    int a[n];
    getInput(a, n);
    cout << "Array before sorting:";
    printArray(a, n);
    quickSort(a, 0, n - 1);
    cout << "\nArray after sorting:";
    printArray(a, n);
    return 0;
}

void quickSort(int a[], int low, int high)
{
    if (low <= high)
    {
        int x = partition(a, high - low + 1, low, high);
        quickSort(a, low, x - 1);
        quickSort(a, x + 1, high);
    }
}

int partition(int a[], int n, int low, int high)
{
    int i, j, p, q, pivot;
    i = low;
    j = low + 1;
    p = low;
    q = high;
    pivot = a[p];
    while (j <= q)
    {
        if (a[j] > pivot)
            j++;
        else
        {
            i++;
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[p], a[i]);
    return i;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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