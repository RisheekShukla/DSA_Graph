#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
    
public:
    vector<int>shortestPath(int v,int e,vector<vector<int>>&edges,int start,int dest)
    {
        vector<pair<int,int>>adj[v+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(v+1);
        vector<int>parent(v+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=1;i<=v;i++)
        {
            dist[i]=1e9;
            parent[i]=i;
        }
        pq.push({0,1});
        dist[1]=0;
        parent[1]=1;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode = it.first;
                int edge_wt = it.second;
                if(dis+edge_wt<dist[adjnode])
                {
                    dist[adjnode]=dis+edge_wt;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        vector<int>ans;
        int node=dest;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node = parent[node];
        } 
        ans.push_back(start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
 
};
int main() 
{
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2},{1, 4, 1},{3, 4, 3},{3, 5, 1},{2, 3, 4},{5, 2, 5}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges,1,5);

    for (auto it:path)
    {
        cout << it << " ";
    }
    cout << endl;
return 0;
}