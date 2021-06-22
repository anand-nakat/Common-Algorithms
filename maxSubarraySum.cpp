#include <iostream>
#include <algorithm>
using namespace std;

void getInput(int[], int n);
void printArray(int[], int);
int calcCrossSum(int[], int, int, int, int);
int maxSumDAC(int[], int, int);
int maxSumKadane(int[], int);

int main()
{
    int n;
    cout << "Enter no of elements in Array:";
    cin >> n;
    int a[n];
    getInput(a, n);
    cout << "\nArray Elements:";
    printArray(a, n);
    cout << "\nMax Subarray sum (DAC): " << maxSumDAC(a, 0, n - 1);
    cout << "\nMax Subarray sum (Kadane's): " << maxSumKadane(a, n);
}

//Solution 1:Using DAC TC:O(nlogn)
int calcCrossSum(int a[], int p, int m, int k, int q)
{
    int mid = (p + q) / 2;
    int leftTotalSum = 0, rightTotalSum = 0, leftBestSum = 0, rightBestSum = 0;
    for (int i = mid; i >= 0; i--)
    {
        leftTotalSum += a[i];
        if (leftTotalSum > leftBestSum)
            leftBestSum = leftTotalSum;
    }
    for (int i = mid + 1; i <= q; i++)
    {
        rightTotalSum += a[i];
        if (rightTotalSum > rightBestSum)
            rightBestSum = rightTotalSum;
    }
    return (leftBestSum + rightBestSum);
}

int maxSumDAC(int a[], int p, int q)
{
    if (p == q)
        return a[p];
    else
    {
        int mid = (p + q) / 2;
        int leftSum = maxSumDAC(a, p, mid);
        int rightSum = maxSumDAC(a, mid + 1, q);
        int crossSum = calcCrossSum(a, p, mid, mid + 1, q);
        return max({crossSum, rightSum, leftSum});
    }
}

//Solution 2:Kadane's Algorithm TC:O(n)
int maxSumKadane(int a[], int n)
{
    int bestMaxSum, currentSum;
    bestMaxSum = currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += a[i];
        if (currentSum > bestMaxSum)
            bestMaxSum = currentSum;
        if (currentSum < 0)
            currentSum = 0; //Reset Sum
    }
    return bestMaxSum;
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