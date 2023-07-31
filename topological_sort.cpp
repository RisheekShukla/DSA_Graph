#include <bits/stdc++.h>
using namespace std;
class Solution {
    // topo sort only exists in DAGs i.e. Direct Acyclic graph
    void dfs(vector<int>adj[],vector<int>&vis,int node,int n,stack<int>&stck)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(adj,vis,it,n,stck);
            }
        }
        stck.push(node);
    }

public:
    // topo sort mtlb agar adj[u]->v
    // then in the traversal u must be visited before v
    stack<int> topo_sort(vector<int>adj[],int n)
    {
        vector<int>vis(n,0);
        // in topo sort here we'll use stack
        stack<int>stck;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis,i,n,stck);
            }
        }
        return stck;
    }
};

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
} 

int main() 
{
     int n=6;
    vector<int>adj[n];
    addEdge(adj,2,3);
    addEdge(adj,3,1);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,5,0);
    addEdge(adj,5,2);
    Solution s1;
    stack<int>ans = s1.topo_sort(adj,n);
    for(int i=0;i<n;i++)
    {
        int n = ans.top();
        ans.pop();
        cout<<n<<" ";
    }
    return 0;
}