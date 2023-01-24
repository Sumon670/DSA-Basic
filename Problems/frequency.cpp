#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int x,int arr[],int low,int high)
{
    if(low==high)
    {
        if(arr[low]==x)
        return 1;
        else
        return 0;
    }
    int mid=(low+high)/2;
    return solve(x,arr,low,mid)+ solve(x,arr,mid+1,high);
}

int main()
{
    int n;
    cout<<"Enter the size of the array";
    cin>>n;
    cout<<"Enter the elements of the array";
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter the number whose frequency is to be found";
    int x;
    cin>>x;
    cout<<solve(x,arr,0,n-1)<<endl;
}