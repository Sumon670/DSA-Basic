//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
        char id;
        int dl;
        int profit;
};
static bool cmp (Job a, Job b){
    return a.profit>b.profit;
}
void solve (Job arr[], int n){
    sort(arr,arr+n,cmp);
    cout<<arr[0].id<<endl;
    bool slot[n];
    int result[n];
    for (int i=0; i<n; i++){
        slot[i]=false;
    }
    for (int i=0; i<n; i++){
        for (int j=min(n,arr[i].dl-1); j>=0; j--){
            if (slot[j]==false){
                slot[j]=true;
                result[j]=i;
                break;
            }
        }
    }
    cout<<"The sequence is: ";
    for (int i=0; i<n; i++){
        if (slot[i]){
            cout<<arr[result[i]].id<<" ";
        }
    }
}
int main()
{
    Job arr[]={ { 'a', 2, 60 },
                { 'b', 1, 100 },
                { 'c', 3, 20 },
                { 'd', 2, 40 },
                { 'e', 1, 20 } };
    int n = sizeof(arr)/sizeof(arr[0]);
    solve(arr,n);
    return 0;
}