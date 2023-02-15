//Matrix chain multiplication
#include<bits/stdc++.h>
using namespace std;
void solve (int arr[], int n){
    int ans[n][n];
    for (int i=1; i<n; i++){
        ans[i][i] = 0;
    }
    for (int l=2; l<n; l++){   
        for (int i=1; i<n-l+1; i++){
            int j=i+l-1;
            ans[i][j] = INT_MAX;
            for (int k=i; k<j; k++){
                int q = ans[i][k]+ans[k+1][j]+arr[i-1]*arr[k]*arr[j];
                ans[i][j] = min(ans[i][j],q);
            }
        }
    }
    cout<<"Answer is: ";
    cout<<ans[1][n-1]<<endl;
}
int main()
{
    int p[5] = {40,20,30,10,30};
    int n = sizeof(p)/sizeof(p[0]);
    solve(p,n);
    return 0;
}