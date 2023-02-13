#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    char id;
    int dl;
    int p;
};
bool cmp (Job a, Job b){
    return (a.p>b.p);
}
void printSequence (Job arr[],int n){
    sort (arr,arr+n,cmp);
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++){
        slot[i]=false;
    }
    for (int i=0; i<n; i++){
        for (int j=min(n,arr[i].dl)-1; j>=0; j--){
            if (slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    cout<<"Job sequence with maximum profit will be: ";
    for (int i=0;i<n;i++){
        if (slot[i])
            cout<<arr[result[i]].id<<" ";
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
    printSequence(arr,n);
    return 0;
}