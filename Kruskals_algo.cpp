#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{ 
    vector<int>size,parent; 
public:
    DisjointSet(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find_parent(int val)
    {
        if(parent[val]==val)
        {
            return val;
        }
        return parent[val]=find_parent(parent[val]); 
    }

    void unite(int u,int v)
    {
        int u_sup_par = find_parent(u);
        int v_sup_par = find_parent(v);
        if(u_sup_par==v_sup_par)
        {
            return;
        }
        if(size[u_sup_par]<size[v_sup_par])
        {
            parent[u_sup_par]=v_sup_par;
            size[v_sup_par]=size[v_sup_par]+size[u_sup_par];
        }
        else
        {
            parent[v_sup_par] = u_sup_par;
            size[u_sup_par] = size[u_sup_par]+size[v_sup_par];
        }
    }
 
};

class Solution
{ 

public:
int spanning_tree(int n,vector<pair<int,int>> adj[])
{
    vector<pair<int,pair<int,int>>>edges;
    // make the adjlist in the edge format
    for(int i=1;i<=n;i++)
    {
        for(auto it:adj[i])
        {
            int adjNode = it.first;
            int wt = it.second;
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet Ds(n);
    // step 1: sort the edgelist in minheap
    sort(edges.begin(),edges.end());
    int mstwt=0;

    for(auto it:edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        // initially u and v does not belong to same component
        if(Ds.find_parent(u)!=Ds.find_parent(v))
        {
            // hence add the adge in your mst
            mstwt = mstwt + wt;
            // but then connect the nodes for further avoidance of a cycle
            Ds.unite(u,v);
        }
    }
    return mstwt;
}
 
};

int main() 
{
    int n = 6; // *T*W*
    vector<vector<int>> edges = {{1, 1, 4}, {2, 1, 2}, {3, 2, 3}, {3, 2, 4}, {4, 1, 5}, {5, 3, 4},{7, 2, 6},{8, 3, 6},{9, 4, 5}};
    vector<pair<int,int>> adj[n+1];
    for(auto it:edges)
    {
        adj[it[1]].push_back({it[2],it[0]});
        adj[it[2]].push_back({it[1],it[0]});
    }
    // vector<vector<int>> adj[n];
    //  for (auto it : edges) {
    //     vector<int> tmp(2);
    //     tmp[0] = it[1];
    //     tmp[1] = it[2];
    //     adj[it[0]].push_back(tmp);

    //     tmp[0] = it[0];
    //     tmp[1] = it[2];
    //     adj[it[1]].push_back(tmp);
    // }
    Solution s1;
    int ans = s1.spanning_tree(n,adj);
    cout<<"The Cost of minimum spanning tree is "<<ans<<endl;
return 0;
}