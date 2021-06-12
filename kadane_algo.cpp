#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   ll n;
   cin >> n;
   ll arr[n];
   set<ll> s;
   
   ll max_so_far = INT_MIN, max_ending_here = 0;
   ll i, j;
   for (i = 0; i < n; i++)
   {
       cin >> arr[i];
       max_ending_here += arr[i];
       
       if (max_so_far < max_ending_here)
       {
           max_so_far = max_ending_here;
       }
       if (max_ending_here < 0)
       {
           max_ending_here = 0;
       }
       s.insert(max_so_far);
   }
   
   for (i = 1; i < n; i++)
   {
       s.insert(arr[i]);
       max_so_far = INT_MIN;
       max_ending_here = 0;
       for (j = i + 1; j < n; j++)
       {
           max_ending_here += arr[j];
           if (max_so_far < max_ending_here)
           {
               max_so_far = max_ending_here;
           }
           if (max_ending_here < 0)
           {
               max_ending_here = 0;
           }
           s.insert(max_so_far);
       }
   }
   
   ll sum = 0;
   for (auto itr : s)
   {
       sum += itr;
   }
   
   cout << sum;
   
   return 0;
}