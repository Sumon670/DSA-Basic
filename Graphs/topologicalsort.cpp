#include<unordered_map>
#include<list>
#include<stack>
void topoSort (int node,vector<bool>&visited,unordered_map<int,list<int>>&adj,stack<int>&s){
    visited[node]=1;
    for (auto nei:adj[node]){
        if (!visited[nei]){
            topoSort(nei,visited,adj,s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int,list<int>>adj;
    for (int i=0; i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    //call dfs topological fn for all components
    vector<bool>visited(v);
    stack<int>s;
    for (int i=0; i<v; i++){
        if (!visited[i])
            topoSort(i,visited,adj,s);
    }
    vector<int>ans;
    while (!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
//if tle comes change unordered map and use vector in that all cases
