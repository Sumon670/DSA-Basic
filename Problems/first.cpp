//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int a = 0, b = 0;
pair<int, int> solve1(int arr[],int low,int high){
    //base case
    if (high==low){
        return make_pair(arr[low],arr[high]);
    }
    if (low == high-1){
        if (arr[low]<arr[high]){
            return make_pair(arr[high],arr[low]);
        }
        else{
            return make_pair(arr[low],arr[high]);
        }
    }
    int mid = (low+high)/2;
    pair<int,int>left = solve1(arr,0,mid);
    pair<int,int>right = solve1(arr,mid+1,high);
    if (right.first > left.first){
        a = right.first; 
        if (right.second > left.first){
            return make_pair(a,right.second);
        }
        else{
            return make_pair(a,left.first);
        }
    }
    else{
        a = left.first;
        if (left.second > right.first){
            return make_pair(a,left.second);
        }
        else{
            return make_pair(a,right.first);
        }
    }
}
pair<int,int> solve2(int arr[],int low, int high){
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
    int mid = (high + low) / 2;
    pair<int,int>left = solve2(arr,low,mid);
    pair<int,int>right = solve2(arr,mid+1,high);
    if (right.first < left.first){
        b = right.first;
        if (left.first<right.second){
            return make_pair(b,left.first);
        }
        else{
            return make_pair(b,right.second);
        }
    }
    else{
        b = left.first;
        if (right.first>left.second){
            return make_pair(b,left.second);
        }
        else{
            return make_pair(b,right.first);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the array: ";
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    pair<int,int>sol1 = solve1(arr,0,n-1); //for getting second max
    pair<int,int>sol2 = solve2(arr,0,n-1); //for getting second min
    cout<<"The second max element is "<<sol1.second<<endl;
    cout<<"The second min element is "<<sol2.second<<endl;
    return 0;
}