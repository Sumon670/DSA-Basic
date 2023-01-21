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
    int max_no = arr[0];
    cout<<max_no<<endl;
    for (int i=1;i<n;i++){
        max_no = max(arr[i],max_no);
        cout<<max_no<<endl; 
    }
    return 0;
}