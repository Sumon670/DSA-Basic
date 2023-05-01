//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
void solve (int arr[], int low, int high, int sum){
    if (low>=high){
        cout << "Not found"<<endl;
        return;
    }
    if (arr[low]+arr[high] < sum ){
        solve (arr,low+1,high,sum);
    }
    else if (arr[low]+arr[high] > sum){
        solve (arr,low,high+1,sum);
    }
    else if (arr[low]+arr[high] == sum){
        cout<<arr[low]<<" "<<arr[high]<<endl;
        return;
    }

}
int main()
{
    int arr[]={1,2,4,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    solve(arr,0,n,sum);
    return 0;
}