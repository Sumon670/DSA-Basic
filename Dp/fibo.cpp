//top-down dp
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int fibo (int n, vector<int>&dp){
    //base case
    if (n<=1)
        return n;
    //step3
    if (dp[n]!=-1){
        return dp[n];
    }
    //step2
    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int main()
{
    int n; cin>>n;
    //step1
    vector<int>dp(n+1);
    for (int i=0; i<n+1; i++){
        dp[i]=-1;
    }
    cout<<fibo(n,dp)<<endl;
    return 0;
}
//tc is O(n) and sc is O(n)

//bottom-up dp
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int n; cin>>n; 
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
}
//space optimization
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int n; cin>>n; 
    int prev1=1;
    int prev2=0;
    if (n==0){
        return prev2;
    }
    for (int i=2; i<=n; i++){
        //shift logic
        int curr = prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
    return 0;
}