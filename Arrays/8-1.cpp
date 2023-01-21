//Writen by CodemanSumon
#include<iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int arr[100];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int maxno = INT_MIN;
    int minno = INT_MAX;
    for (int j=0; j<n; j++){
        maxno = max(maxno,arr[j]);
        minno = min(minno,arr[j]);
    }

    cout<<maxno<<" "<<minno<<endl;



    return 0;
} 