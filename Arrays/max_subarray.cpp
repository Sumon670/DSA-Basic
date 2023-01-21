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
    int mx_sum = INT_MIN;
    for (int i=0; i<n; i++){
        for (int j=i;j<n;j++){
            int sum = 0;
            for (int k=i; k<=j; k++){
                //cout<<arr[k]<<" ";
                sum = sum+arr[k];
            }//cout<<endl;
            mx_sum = max(mx_sum,sum);
        }
    }
    cout<<mx_sum<<endl;
    return 0;
}