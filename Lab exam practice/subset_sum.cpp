//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
void subsetsum (int set[], int pos, int sum, int temp, int size, bool &f){
    if (sum == temp){
        f = true;
    }
    for (int i=pos; i<size; i++){
        if (temp+set[i] <= sum){
            temp += set[i];
            subsetsum(set,i+1,sum,temp,size,f);
            temp -= set[i];
        }
    }
}
int main()
{
    int set[] = {1,2,3};
    bool f = false;
    int sum = 3;
    int n = sizeof(set);
    //just call function and done
    subsetsum(set,0,sum,0,n,f);
    if (f)
        cout << "Found"<<endl;
    else
        cout <<"Not found"<<endl;
    return 0;
}