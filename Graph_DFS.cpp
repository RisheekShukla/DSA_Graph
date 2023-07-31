#include <bits/stdc++.h>
using namespace std;
class SOLUTION
{
    public:
void Depth_first(vector<int>adj[],int root,int vis[],vector<int>&ans);
};

void SOLUTION::Depth_first(vector<int>adj[],int root,int vis[],vector<int>&ans)
{
    vis[root]=1;
    ans.push_back(root);
    for(auto it:adj[root])
    {
        if(!vis[it])
        {
            Depth_first(adj,it,vis,ans);
        }
    }
}

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
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
int n=7;
vector<int>adj[8];

// addEdge(adj,0,1);
addEdge(adj,1,5);
addEdge(adj,1,6);
addEdge(adj,5,3);
addEdge(adj,5,2);
addEdge(adj,2,7);
addEdge(adj,6,4);
addEdge(adj,7,4);
int visited[n+1]={0};
vector<int>ans;
SOLUTION s1;
s1.Depth_first(adj,1,visited,ans);
printans(ans);
return 0;
}