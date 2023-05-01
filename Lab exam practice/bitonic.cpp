//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int bitonic (int arr[], int low, int high){
    if (low <= high){
        int mid = (high+low)/2;
        if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if (arr[mid]>arr[mid-1]){
            return bitonic(arr,low,mid-1);
        }
        else{
            return bitonic(arr,mid+1,high);
        }
    }
}
int main()
{
    int arr[] = {6, 7, 8, 11, 9, 5, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = bitonic(arr, 0, n-1);
    cout << arr[index];
    return 0;
}