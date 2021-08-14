#include<iostream>
using namespace std;

void swap (int *one, int *two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}

void selectionSort (int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {64, 35, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}