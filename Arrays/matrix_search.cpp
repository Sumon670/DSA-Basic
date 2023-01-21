//Writen by CodemanSumon
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    int mat[100][100];
    cout<<"Enter range: ";
    cin >> n >> m;
    cout<<"Enter matrix: ";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    int r=0;
    int c=m-1;
    bool found = false;
    int target;
    cout<<"Enter target: ";
    cin>>target;
    while (r<n && c>=0){
        if (mat[r][c] == target){
            found = true;
        }
        if (mat[r][c]>target){
            c--;
        }
        else{
            r++;
        }
        
    }
    if (found){
        cout<<"Element is found in matrix."<<endl;

    }
    else{
        cout<<"Element is not found in matrix."<<endl;
    }
    return 0;
}