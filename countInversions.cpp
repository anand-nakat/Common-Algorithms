#include <iostream>
using namespace std;
int countInversionsBruteForce(int a[], int n);
int countInversionsDAC(int a[], int, int);
int mergeAlgo(int a[], int i, int mid, int k, int j);
void getInput(int a[], int n);

int main()
{
    int n, inversions;
    cout << "Enter no of elements in Array:";
    cin >> n;
    int a[n];
    getInput(a, n);
    inversions = countInversionsBruteForce(a, n);
    cout << "\nBrute Force:No of Inversions are:" << inversions;
    inversions = countInversionsDAC(a, 0, n - 1);
    cout << "\nDAC:No of Inversions are:" << inversions;
}
int countInversionsDAC(int a[], int low, int high)
{
    int inversions, leftInversions, rightInversions;
    inversions = leftInversions = rightInversions = 0;
    if (low == high)
        return 0;
    else
    {
        int mid = (low + high) / 2;
        leftInversions = countInversionsDAC(a, low, mid);
        rightInversions = countInversionsDAC(a, mid + 1, high);
        inversions += mergeAlgo(a, low, mid, mid + 1, high);
        return (inversions + leftInversions + rightInversions);
    }
}

int mergeAlgo(int a[], int i, int mid, int k, int j)
{
    int inversions = 0, l = 0, low = i, m = j - i + 1;
    int b[m];
    while (i <= mid && k <= j)
    {
        if (a[i] >= a[k]) //Smaller Element coming from right side
        {
            b[l++] = a[k++];
            inversions += mid - i + 1;
        }
        else //Smaller element coming from left side
            b[l++] = a[i++];
    }
    while (k <= j)
        b[l++] = a[k++];
    while (i <= mid)
        b[l++] = a[i++];
    for (int i = low, j = 0; j < m; i++, j++)
        a[i] = b[j];
    return inversions;
}
int countInversionsBruteForce(int a[], int n)
{
    int inversions = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                inversions++;
        }
    }
    return inversions;
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