#include<unordered_map>
#include<list>
bool checkCycleDFS(int node, unordered_map<int,bool>&visited,
                   unordered_map<int,bool>&DFSvisited,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    DFSvisited[node]=true;
    for (auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cyclefound = checkCycleDFS(neighbour,visited,DFSvisited,adj);
            if (cyclefound)
                return true;
        }
        else if (DFSvisited[neighbour]){
            return true;
        }
    }
    DFSvisited[node] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // create adj list
    unordered_map<int,list<int>>adj;
    for (int i=0; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    //call dfs for all component
    unordered_map<int,bool>visited;
    unordered_map<int,bool>DFSvisited;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            bool cycleFound = checkCycleDFS(i,visited,DFSvisited,adj);
            if (cycleFound)
                return true;
        }
    }
    return false;
}
//T.C = O(N+E) S.C=linear