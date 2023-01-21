//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int curr_sum[n+1];
    curr_sum[0] = 0;
    for (int i=1; i<=n; i++){
        curr_sum[i] = curr_sum[i-1]+arr[i-1];
    }
    int mxsum = INT_MIN;
    for (int i=1; i<=n; i++){
        int sum=0;
        for (int j=0; j<i; j++){
            sum = curr_sum[i] - curr_sum[j];
            mxsum = max(sum,mxsum);
        }
    }
    cout<<mxsum<<endl;
    return 0;
}