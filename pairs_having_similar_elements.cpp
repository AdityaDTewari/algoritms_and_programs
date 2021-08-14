#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;

    cin>>n;
    long long int arr[n], count1 = 0, sum = 0, count2 = 0;

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0; i<n; i++)
    {
        if((arr[i+1]-arr[i])==1)
        {
            count1++;
        }
        else if(arr[i+1]==arr[i])
        {
            count2++;
            count1++;
        }
        else
        {
            if(count1!=count2)
            {
                sum+= (count1*(count1+1))/2;
            }
            count1=0;
            count2=0;
        }
    }
    
    cout<<sum<<endl;

    return 0;
}