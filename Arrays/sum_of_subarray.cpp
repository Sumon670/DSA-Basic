//Writen by CodemanSumon
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter range: ";
    cin>>n;
    int arr[1000];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    for (int i=0;i<n;i++){
        int current = 0;
        for (int j=i;j<n;j++){
            current += arr[j];
            cout<<current<<endl;
        }
    }
    return 0;
}