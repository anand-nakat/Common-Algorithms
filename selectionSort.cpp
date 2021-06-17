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
void selectionSort(int a[], int n)
{
    int min, j, i, minIndex;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minIndex = j;
            }
        }
        swap(&a[i], &a[minIndex]);
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
    selectionSort(a, n);
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