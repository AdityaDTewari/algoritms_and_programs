#include <iostream>
#include <limits.h>

using namespace std;

int minXOR(int arr[], int n)
{
    int min_xor = INT_MAX;
    
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            min_xor = min(min_xor, arr[i]^arr[j]);
        }
    }
    return min_xor;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minXOR(arr, 5) << endl;
    return 0;
}