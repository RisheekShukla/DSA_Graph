#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int>adj[],int root,int vis[],vector<int>&ans)
{
    // recursion ek connection bna rha h
    vis[root]=1;
    ans.push_back(root);
    for(auto it:adj[root]) // ye condition use ek hi side traverse krwa rhi h
    {
        if(!vis[it])
        {
            dfs(adj,it,vis,ans);
        }
    }
}

void printans(vector<int>ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main()
{
    int n = 4;
    vector<int>adj[n+1];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,1);
    int vis[n+1]={0};
    vector<int>ans;
    dfs(adj,1,vis,ans);
    printans(ans);
    return 0;
}