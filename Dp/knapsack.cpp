#include <bits/stdc++.h> 
int solve (vector<int> &weight, vector<int> &value, int index, int capacity){
    //base case
    if (index == 0){
        if (weight[index] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int incl = 0;
    if (weight[index] <= capacity){
        incl = value[index]+solve(weight,value,index-1,capacity-weight[index]);
    }
    int excl = solve(weight,value,index-1,capacity);
    int ans = max(incl,excl);
    return ans;
}
int solveMem (vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
    //base case
    if (index == 0){
        if (weight[index] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    if (dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int incl = 0;
    if (weight[index] <= capacity){
        incl = value[index]+solveMem(weight,value,index-1,capacity-weight[index],dp);
    }
    int excl = solveMem(weight,value,index-1,capacity,dp);
    dp[index][capacity] = max(incl,excl);
    return dp[index][capacity];
}
int solveTab (vector<int> &weight, vector<int> &value, int n, int capacity){
    //step 1
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    //step 2
    for (int w=weight[0]; w<=capacity; w++){
        if (weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }
    for (int i=1; i<n; i++){
        for (int w=0; w<=capacity; w++){
            int incl = 0;
            if (weight[i]<=w){
                incl = value[i] + dp[i-1][w-weight[i]];
            }
            int excl = dp[i-1][w];
            dp[i][w] = max(incl,excl);
        }
    }
    return dp[n-1][capacity];
}
int solveSpace (vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);
    for (int w=weight[0]; w<=capacity; w++){
        if (weight[0] <= capacity){
            curr[w] = value[0];
        }
        else{
            curr[w] = 0;
        }
    }
    for (int i=1; i<n; i++){
        for (int w=capacity; w>=0; w--){
            int incl = 0;
            if (weight[i]<=w){
                incl = value[i] + curr[w-weight[i]];
            }
            int excl = curr[w];
            curr[w] = max(incl,excl);
        }
    }
    return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    //return solve(weight,value,n-1,maxWeight);
    //vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    //return solveMem (weight,value,n-1,maxWeight,dp);
    return solveSpace (weight,value,n,maxWeight);
}