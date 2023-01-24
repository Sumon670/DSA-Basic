#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
void solve(int arr[],int low,int high,int x)
{
    if(low>=high)
    {
        cout<<"Not found";
        return;
    }
    //cout<<arr[low]<<arr[high]<<endl;
    int mid = (low+high)/2;
    if(arr[low]+arr[high]<x)
    {
        solve(arr,low+1,high,x);
    }
    else if(arr[low]+arr[high]>x)
    {
        solve(arr,low,high-1,x);
    }
    else if(arr[low]+arr[high]==x)
    {
        cout<<arr[low]<<" "<<arr[high];
        return;
    }

}
int main()
{
    int arr[6]={1,2,4,5,6,8};
    solve(arr,0,5,10);
}