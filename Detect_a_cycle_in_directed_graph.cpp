#include <bits/stdc++.h>
using namespace std;

// Using DFS
bool dfs(vector<int>adj[],vector<int>&vis,int start,vector<int>pathvis)
{
    vis[start]=1;
    pathvis[start]=1;
    for(auto it:adj[start])
    {
        if(!vis[it])
        {
            // by default ye false dega lekin agar cycle hai to hr call ko true return kare
            if(dfs(adj,vis,it,pathvis)==true)
            {
                return true;
            }
        }
        // or agar us traversal me esa branch mil jaye jo ki visited ho
        // and usko same traversal path me visit kiya gya ho i.e pathvis[start]==pathvis[it]==1
        else if(pathvis[it])
        {
            return true;
        }
    }
    // wapas jate huye us pathvis ko zero krde
    pathvis[start]=0;
    return false;
}

Using BFS 
bool detect_a_cycle(vector<int>adj[],vector<int>&vis,int n,int start)
{
    queue<int>qrr;
    vector<int>vis

}

// every connected components tk reach ke liye
bool check_comp(vector<int>adj[],int n,int root)
{
    // vis hr ek element ka visiting record rkhta hai
    vector<int>vis(n,0);
    // pathvis that particular branch ka traversal record rkhta hai
    vector<int>pathvis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(adj,vis,i,pathvis) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}

int main() 
{

    int n=8;
    vector<int>adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,5,7);
    cout<<check_comp(adj,n,0);
return 0;
}