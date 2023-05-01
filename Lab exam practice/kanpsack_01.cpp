//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class Item{
    public:
        int profit;
        int weight;
        Item(int p, int w){
            this->profit=p;
            this->weight=w;
        }
};
int solveRec (vector<Item>&items, int capacity, int index){
    if (index==0){
        if (items[index].weight <= capacity){
            return items[index].profit;
        }
        else{
            return 0;
        }
    }
    int incl=0;
    if (items[index].weight <= capacity){
        incl += items[index].profit+solveRec(items,capacity-items[index].weight,index-1);
    }
    int excl = solveRec (items,capacity,index-1);
    int ans = max(incl,excl);
    return ans;
}
int solveMem (vector<Item>&items, int capacity, int index, vector<vector<int>>&dp){
    if (index==0){
        if (items[index].weight <= capacity){
            return items[index].profit;
        }
        else{
            return 0;
        }
    }
    if (dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int incl=0;
    if (items[index].weight <= capacity){
        incl = items[index].profit+solveMem(items,capacity-items[index].weight,index-1,dp);
    }
    int excl = solveMem (items,capacity,index-1,dp);
    int ans = max(incl,excl);
    dp[index][capacity]=ans;
    return dp[index][capacity];
}
int main()
{
    vector<Item> items;
    Item item1 (1,4);
    Item item2 (2,5);
    Item item3 (3,1);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    int n = items.size();
    int capacity = 3;
    //int ans = solveRec(items,capacity,n);
    //cout<<ans<<endl;
    vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
    int ans = solveMem(items,capacity,n-1,dp);
    cout<<ans<<endl;
    return 0;
}