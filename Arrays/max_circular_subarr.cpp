//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int kedane (int arr[], int n){
    int curr = 0;
    int mx = INT_MIN;
    for (int i=0; i<n; i++){
        curr += arr[i];
        if (curr<0){
            curr =0;
        }
        mx = max(mx,curr);
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int wrap_sum;
    int nonwrap_sum;
    int total_sum = 0;
    nonwrap_sum = kedane (arr,n);
    for (int i=0; i<n; i++){
        total_sum += arr[i];
        arr[i] = -arr[i];
    }
    wrap_sum = total_sum + kedane(arr,n);
    cout<<max(wrap_sum,nonwrap_sum)<<endl;
    return 0;
}