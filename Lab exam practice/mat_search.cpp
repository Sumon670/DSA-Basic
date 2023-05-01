//Writen by CodemanSumon
#include<bits/stdc++.h>
#define n 3
#define m 3
using namespace std;
bool search_1d (int arr[],int k){
    int low = 0;
    int high = n-1;
    while (low<=high){
        int mid = low + (high-low) / 2;
        if (arr[mid] == k){
            return true;
        } 
        if (arr[mid] > k){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
}
bool search (int matrix[m][n], int k){
    int low = 0;
    int high = m-1;
    while (low <= high){
        int mid = low + (high-low) / 2;
        if (k>=matrix[mid][0] && k<=matrix[mid][n-1]){
            return search_1d(matrix[mid],k);
        }
        if (k < matrix[mid][0]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
}
int main()
{
    int mat[m][n] = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 7;
    if (search(mat,k))
        cout << "Found"<<endl;
    else
        cout <<"Not found"<<endl;
    return 0;
}