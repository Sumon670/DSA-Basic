//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
void solve (int s, int d){
    if (s==0){
        if (d==1){
            cout<<0;
            return;
        }
        else{
            return;
        }
    }
    if (s > 9*d){
        return;
    }
    int ans[d];
    s = s-1;
    for (int i=d-1; i>=0; i--){
        if (s > 9){
            ans[i]=9;
            s=s-9;
        }
        else{
            ans[i]=s;
            s=0;
        }
    }
    ans[0]=s+1;
    for (int i=0; i<d; i++){
        cout << ans[i]<<" ";
    }
}
int main()
{
    int s,d;
    cin>>s>>d;
    solve(s,d);
    return 0;
}