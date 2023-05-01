//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int solve (int matrix[], int n){
    int ans[n][n];
    for (int i=0; i<n; i++){
        ans[i][i]=0;
    }
    for (int l=2; l<n; l++){
        for (int i=0; i<n-l+1; i++){
            int j=i+l-1;
            ans[i][j]=INT_MAX;
            for (int k=i; k<j; k++){
                int q = ans[i][k]+ans[k+1][j]+(matrix[i-1]*matrix[j]*matrix[k]);
                ans[i][j]=min(q,ans[i][j]);
            }
        }
    }
    return ans[1][n-1];
}
int main()
{
    int matrix[]={40,20,30,10,30};
    int n = sizeof(matrix)/sizeof(matrix[0]);
    cout << solve (matrix,n) << endl;
    return 0;
}
