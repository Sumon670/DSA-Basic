//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
pair<int,int> solve (int arr[],int low,int high){
    //base case
    if (low == high){
        return make_pair(arr[low],arr[high]);
    }
    if (low == high-1){
        if (arr[low]>arr[high]){
            return make_pair(arr[low],arr[high]);
        }
        else{
            return make_pair(arr[high],arr[low]);
        }
    }
    int mid = (low+high)/2;
    pair<int,int> left = solve(arr,0,mid);
    pair<int,int> right = solve(arr,mid+1,high);
    if (left.first > right.first){
        if (left.second>right.first){
            return make_pair(left.first,left.second);
        }
        else{
            return make_pair(left.first,right.first);
        }
    }
    else{
        if (right.second>left.first){
            return make_pair(right.first,right.second);
        }
        else{
            return make_pair(right.first,left.first);
        }
    }
}
pair<int,int>sol (int arr[], int low, int high){
    if (low==high){
        return make_pair(arr[low],arr[high]);
    }
    if (low==high-1){
        if (arr[low]<arr[high]){
            return make_pair(arr[low],arr[high]);
        }
        else{
            return make_pair(arr[high],arr[low]);
        }
    }
    int mid = (low+high)/2;
    pair<int,int>left = sol(arr,0,mid);
    pair<int,int>right = sol(arr,mid+1,high);
    if (left.first<right.first){
        if (left.second<right.first){
            return make_pair(left.first,left.second);
        }
        else{
            return make_pair(left.first,right.first);
        }
    }
    else{
        if (right.second<left.first){
            return make_pair(right.first,right.second);
        }
        else{
            return make_pair(right.first,left.first);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array element: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    pair<int,int> large = solve(arr,0,n-1); 
    pair<int,int> small = sol(arr,0,n-1); 
    cout<<"The second largest element is: "<<large.second<<endl;
    cout<<"The second smallest element is: "<<small.second<<endl;
    return 0;
}