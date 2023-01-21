//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
void towerofhanoi(int n, char src, char helper, char dest){
    if (n==1){
        cout<<"Move 1th disk from "<<src<<" to "<<dest<< endl;
        return;
    }
    towerofhanoi(n-1,src,dest,helper);
    cout<<"Move "<<n<<"th disk from "<<src<<" to "<<dest<<endl;
    towerofhanoi(n-1,helper,src,dest);
}
int main()
{
    towerofhanoi(4,'A','B','C');
    return 0;
}