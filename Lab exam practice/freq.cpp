//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int solve (int x, int arr[], int low, int high){
    if (low==high){
        if (arr[low]==x){
            return 1;
        }
        else{
            return 0;
        }
    }
    int mid = (low+high)/2;
    return solve(x,arr,low,mid) + solve(x,arr,mid+1,high);
}
int main()
{
    int arr[]= {1,2,3,4,4,4,5};
    cout << solve(4,arr,0,6);
    return 0;
}