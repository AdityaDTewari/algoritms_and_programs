// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
 
int mergeSort(int arr[], int temp[], int l, int r);
int merge(int arr[], int temp[], int l, int m, int r);

int mergeSortTemp(int arr[], int arr_size)
{
    int temp[arr_size];
    return mergeSort(arr, temp, 0, arr_size-1);
}

int mergeSort(int arr[], int temp[], int l, int r)
{
    int m, i_count = 0;
    if (r > l) {

        m = (r + l) / 2;

        i_count += mergeSort(arr, temp, l, m);
        i_count += mergeSort(arr, temp, m+1, r);

        i_count += merge(arr, temp, l, m+1, r);
    }
    return i_count;
}

int merge(int arr[], int temp[], int l, int m, int r)
{
    int i = l;
    int j = m;
    int k = l;
    int i_count = 0;
    
    while ((i <= m-1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            i_count += (m-i);
        }
    }

    while (i <= m-1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
 
    return i_count;
}

int main()
{
    // Write C++ code here
    int arr[] = {10, 20, 16, 4, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int i_count = mergeSortTemp(arr, n);
    cout << i_count;
    return 0;
}