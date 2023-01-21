//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void permute (vector<int>&a, int idx){
    if (idx == a.size()){
        ans.push_back(a);
        return;
    }
    for (int i=idx; i<a.size(); i++){
        swap(a[i],a[idx]);
        permute (a,idx+1);
        swap(a[i],a[idx]);
    }
    return;
}
int main()
{
    int n; cin>>n;
    vector<int>a(n);
    for (auto &i:a)
        cin>>i;
    //permute (a,0);
    sort(a.begin(),a.end());
    do{
        ans.push_back(a);
    }while (next_permutation(a.begin(),a.end())); //short trick using STL
    for (auto v:ans){
        for (auto i:v){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}  //O(N!) time complexity