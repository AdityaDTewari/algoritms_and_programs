// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int invCount(int arr[], int n)
{
    int i_count = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                i_count++;
            }
        }
    }
    return i_count;
}
int main() {
    // Write C++ code here
    int arr[] = {10 , 20, 6, 14, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << invCount(arr, n);
    return 0;
}