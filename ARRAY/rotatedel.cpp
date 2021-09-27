//rotate and delete
//https://practice.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;   cin>>t;
    while(t--){
        ll n;  cin>>n;
        ll arr[n+1];
        for(int i=0 ; i<n ; i++) cin>>arr[i];

        if(n==1)
            cout<<arr[0]<<endl;
        else if(n%2)
        {
            ll ind = n-3;
            ind = floor(ind/4);
            ind = 3+ind;
            cout<<arr[ind-1]<<endl;
        }
        else
        {
            ll ind = n-2;
            ind = floor(ind/4);
            ind = 2+ind;
            cout<<arr[ind-1]<<endl;
        }
    }
    return 0;
}
