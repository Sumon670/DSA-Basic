//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
void dfs (int node, int parent, vector<int>&dis, vector<int>&low,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,vector<int>&ap,int timer){
    vis[node]=true;
    dis[node]=low[node]=timer++;
    int child = 0;
    for (auto i:adj[node]){
        if (i == parent){
            continue;
        }
        if (!vis[i]){
            dfs(i,node,dis,low,vis,adj,ap,timer);
            low[node]=min(low[node],low[i]);
            //check ap 
            if (low[i] >= dis[node] && parent!=-1){
                ap[node]=1; 
            }
            child++;
        }
        else{
            low[node]=min(low[node],dis[i]);
        }
    }
    if (parent == -1 && child>1){
        ap[node] = 1;
    }
}
int main()
{
    int n = 5;
    int e = 5;
    vector<pair<int,int>>edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    //adj list
    unordered_map<int,list<int>>adj;
    for (int i=0; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int>dis(n);
    vector<int>low(n);
    unordered_map<int,bool>vis;
    vector<int>ap(n,0);
    for(int i=0; i<n; i++){
        dis[i]=-1;
        low[i]=-1;
    }
    //dfs
    for (int i=0; i<n; i++){
        if (!vis[i]){
            dfs(i,-1,dis,low,vis,adj,ap,timer);
        }
    }
    //print ap
    cout<<"Articulation points are "<<endl;
    for (int i=0; i<n; i++){
        if (ap[i] != 0 )
            cout<<i<< " ";
    }cout<<endl;
    return 0;
}
//tc is O(N+E) and sc is linear i.e. O(N)