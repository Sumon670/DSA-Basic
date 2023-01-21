//Writen by CodemanSumon
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,n3;
    int m1[100][100];
    int m2[100][100], ans[100][100];
    cout<<"Enter range: ";
    cin>>n1>>n2>>n3;
    cout<<"\n";
    cout<<"Enter matrix 1: ";
    for (int i=0; i<n1; i++){
        for (int j=0; j<n2; j++){
            cin>>m1[i][j];
        }
    }
    cout<<"\n";
    cout<<"Enter matrix 2: ";
    for (int i=0; i<n2; i++){
        for (int j=0; j<n3; j++){
            cin>>m2[i][j];
        }
    }
    for (int i=0; i<n1; i++){
        for (int j=0; j<n3; j++){
            ans[i][j] = 0;
        }
    }
    cout<<"The answer is: "<<endl;
    for (int i=0; i<n1; i++){
        for (int j=0; j<n3; j++){
            for (int k=0; k<n2; k++){
                ans[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    for (int i=0; i<n1; i++){
        for (int j=0; j<n3; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}