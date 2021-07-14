#include <iostream>
#include <math.h>
using namespace std;

void getInput(int a[], int n);
void printArray(int a[], int);
int n, n_copy;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapElement(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int a[], int i)
{
    int child1_idx = 2 * i + 1;
    int child2_idx = 2 * i + 2;
    if (child1_idx >= n) /*No child then return*/
        return;
    if (child2_idx >= n) /* Left Child but not Right Child */
    {
        if (a[i] < a[child1_idx])
            swapElement(&a[i], &a[child1_idx]);
        return;
    }
    int idx = a[child1_idx] > a[child2_idx] ? child1_idx : child2_idx;
    if (a[i] > a[idx]) /*Child Ok*/
        return;
    swapElement(&a[i], &a[idx]);
    maxHeapify(a, idx); /*Call recursively for swapped parent*/
}

void buildHeap(int a[]) /*Build Heap: O(n)*/
{
    if (n == 1 || n == 0)
        return;
    if (n == 2)
    {
        if (a[0] < a[1])
            swapElement(&a[0], &a[1]);
        return;
    }
    for (int i = n - ceil(n / 2) - 1; i >= 0; i--) //Start with last parent node
    {
        maxHeapify(a, i);
    }
}

void deleteFromHeap(int a[]) /*O(logn)*/
{
    if (n == 1)
        return;
    swapElement(&a[0], &a[n - 1]); /*Swap Root with Last Leaf Node*/
    n--;                           /*Max Element stored at nth Index*/
    maxHeapify(a, 0);
}

void heapSort(int a[])
{
    buildHeap(a); /*O(n)*/
    cout << "\nMax Heap:";
    printArray(a, n_copy);
    for (int i = 0; i < n_copy - 1; i++) /*Deletion n times:O(nlogn) */
        deleteFromHeap(a);
}

int main()
{
    cout << "Enter no of elements in Array:";
    cin >> n;
    n_copy = n;
    int a[n];
    getInput(a, n);
    cout << "\nArray Before sorting:";
    printArray(a, n);
    heapSort(a);
    cout << "\nArray After sorting:";
    printArray(a, n_copy);
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