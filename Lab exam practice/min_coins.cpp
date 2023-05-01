//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
int minCoins (int coins[], int x){
    if (x==0){
        return 0;
    }
    if (x < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i=0; i<sizeof(coins); i++){
        int ans = minCoins(coins,x-coins[i]);
        if (ans != INT_MAX){
            mini = min (mini,1+ans);
        }
    }
    return mini;
}
int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "<< minCoins(coins,V);
    return 0;
}