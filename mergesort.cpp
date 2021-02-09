#include <iostream>
using namespace std;

void merge(int arr[], int l, int r, int m){
    //temp arr sizes
    int n1 = m-l+1;
    int n2 = r-m;
    //temp arrs
    int L[n1];
    int R[n2];
    //filling the arrs
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    //indexes for all arrs
    int i = 0;
    int j = 0;
    int k = l;
    //merging
    while( i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //copy remaining elements if remaining
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]= R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    else{
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, r, m);
    }
}
void printArray(int arr[], int n){
    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[] = {5, 4, 2, 3, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size-1);
    cout<<endl;
    printArray(arr, arr_size);
    return 0;
    
}