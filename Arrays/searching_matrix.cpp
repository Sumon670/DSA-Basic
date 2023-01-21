//Writen by CodemanSumon
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"enter range: ";
    cin>>n>>m;
    int arr[100][100];
    cout<<"enter matrix: ";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int x;
    cout<<"enter the element: ";
    cin>>x;
    bool flag = false;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] == x){
                cout<<i<<" "<<j<<endl;
                flag = true;
            }
        }
    }
    if (flag){
        cout<<"Element is found."<<endl;
    }
    else{
        cout<<"Element is not found."<<endl;
    }
    return 0;
}