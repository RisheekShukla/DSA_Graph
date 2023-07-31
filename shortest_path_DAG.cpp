#include <bits/stdc++.h>
using namespace std;
class Solution 
{ 
    // topo sort isliye kara taki hame pta chale ki kha se hote hue jana hai
    void topodfs(vector<pair<int,int>>adj[],vector<int>&vis,int node,stack<int>&stck)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            int v = it.first;
            if(!vis[v])
            {
                topodfs(adj,vis,v,stck);
            }
        }
        stck.push(node);
    }
public:
    vector<int>shortest_path(int n,int m,vector<vector<int>>&edges)
    {
        // our edges are in the form of [u,v,wt]
        // we need to create an adj list with 
        // u as index and insert {v,wt} in pair format
        vector<pair<int,int>>adj[n];
        
        // filling adj list
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }

        // first do the topo_sort
        // here we are using a dfs approach
        vector<int>vis(n,0);
        stack<int> stck;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                topodfs(adj,vis,i,stck);
            }
        }
        
        // now create distance array
        vector<int>dist(n);
        for(int i=0;i<n;i++)dist[i]=INT_MAX;
        // taking source as 0 (obviously distance of 0 to 0 is 0)
        dist[0]=0;
        // pulling each element from the topo ordered stack
        while(!stck.empty())
        {
            int node = stck.top();
            stck.pop();
            for(auto it:adj[node])
            {
                int v = it.first;
                int wt = it.second;
                // parent + current node(weight) < initial weight
                if(dist[node]+wt<dist[v])
                {
                    dist[v] = dist[node]+wt;
                }
            }
        }
        return dist;      
    }
};

int main() 
{
    int n=6,
        m=7;
    vector<vector<int>>edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    Solution s1;
    vector<int>ans = s1.shortest_path(n,m,edges);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
return 0;

}