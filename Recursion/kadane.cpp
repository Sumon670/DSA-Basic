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
    int curr_sum = 0;
    int mxsum = INT_MIN;
    for (int i=0; i<n; i++){
        curr_sum += arr[i];
        if (curr_sum<0){
            curr_sum = 0;
        }
        mxsum = max(mxsum,curr_sum);
    }
    cout<<mxsum<<endl;
    return 0;
}

//Kedane's Algorithm
