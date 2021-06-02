#include <iostream>
// #include <utility>
using namespace std;

void getInput(int a[], int);
void printArray(int a[], int n);
int partition(int a[], int low, int high);
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int selectionProcedure(int a[], int low, int high, int k)
{
    if (low <= high)
    {
        int m = partition(a, low, high);
        if (m == k - 1)
            return a[m];
        else if (k - 1 > m)
            selectionProcedure(a, m + 1, high, k);
        else
            selectionProcedure(a, low, m - 1, k);
    }
}

int partition(int a[], int low, int high)
{
    int pivot, i, j;
    pivot = a[low];
    i = low;
    j = low + 1;

    for (j = low + 1; j <= high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i], a[low]);
    return i;
}

int main()
{
    int n, k;
    cout << "Enter no of elements:";
    cin >> n;
    int a[n];
    getInput(a, n);
    printArray(a, n);

    cout << "\nEnter k (for kth smallest):";
    cin >> k;
    while (k > n)
    {
        cout << "\nInvalid value of k! Enter again:\n";
        cin >> k;
    }

    int kthSmallest = selectionProcedure(a, 0, n - 1, k);
    cout << k << "th smallest element:" << kthSmallest;
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