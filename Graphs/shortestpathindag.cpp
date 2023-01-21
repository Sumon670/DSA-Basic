//Writen by CodemanSumon
#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addedge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adj[u].push_back(p);
    }
    void printadj(){
        for (auto i:adj){
            cout<<i.first<<"->";
            for (auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool>&vis,stack<int>&topo){
        vis[node]=true;
        for (auto neighbour:adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first,vis,topo);
            } 
        }
        topo.push(node);
    }
    void getshortestpath(int src,vector<int>&distance,stack<int>&topo){
        distance[src]=0;
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            if (distance[top]!=INT_MAX){
                for (auto i:adj[top]){
                    if (distance[top]+i.second < distance[i.first]){
                        distance[i.first]=distance[top]+i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    // g.addedge(0,1,5);
    // g.addedge(0,2,3);
    // g.addedge(1,2,2);
    // g.addedge(1,3,6);
    // g.addedge(2,3,7);
    // g.addedge(2,4,4);
    // g.addedge(2,5,2);
    // g.addedge(3,4,-1);
    // g.addedge(4,5,-2);
    // g.addedge(1,2,1);
    // g.addedge(2,4,1);
    // g.addedge(3,1,1);
    // g.addedge(3,2,-1);
    // g.addedge(3,4,-1);
    // g.addedge(3,5,1);
    // g.addedge(4,5,1);
    // g.addedge(5,6,-1);
    // g.addedge(6,3,-1);
    g.printadj();
    //topological sort
    unordered_map<int,bool>visited;
    stack<int>s;
    for (int i=0; i<6; i++){
        if (!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    int src=1;
    vector<int>distance(6);
    for (int i=0;i<6;i++){
        distance[i]=INT_MAX;
    } 
    g.getshortestpath(src,distance,s);
    cout<<"answer is: "<<endl;
    for (int i=0; i<distance.size(); i++){
        cout<<distance[i]<<" ";
    }cout<<endl;
    return 0;
}//sc & tc is O(N+E)