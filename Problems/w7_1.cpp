#include<bits/stdc++.h>
using namespace std;
void solve(int s,int d){
    if (s==0){
        if (d==1){
            cout<<"Smallest number: "<<0;
            return;
        }
        else{ 
            cout<<"Not possible";
            return;
        }
    }
    if (s>9*d){
        cout<<"Not possible";
        return;
    }
    int ans[d];
    s = s-1;
    for (int i=d-1; i>0; i--){
        if (s>9){
            ans[i]=9;
            s=s-9;
        }else{
            ans[i]=s;
            s=0;
        }
    }
    ans[0]=s+1;
    cout<<"Smallest number: ";
    for (int i=0; i<d; i++){
        cout<<ans[i];
    }
}
int main()
{
    int s,d;
    cout<<"Enter sum of the digits and number of the digits: ";
    cin>>s>>d;
    solve(s,d);
    return 0;
}
