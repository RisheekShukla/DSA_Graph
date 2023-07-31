#include <bits/stdc++.h>
using namespace std;

// DFS Approach
bool DetectCycle(vector<int>adj[],int src,int p,vector<int>&vis)
{  
    vis[src] = 1;
    for(auto it:adj[src])
    {
        if(!vis[it])
        {
            vis[it]=1;
            DetectCycle(adj,it,src,vis);
        }
        else if(it!=p)
        {
            return true;
        }
    }
    return false;
}

// BFS Approach
// bool Detect_a_cycle(vector<int>adj[],int i,int n,vector<int>&vis)
// {   // queue is containing the {current vertice, vertice who called it}
//     queue<pair<int,int>>qrr;
//     qrr.push({i,-1});
//     vis[i]=1;
//     while(!qrr.empty())
//     {
//         int p = qrr.front().first;
//         int q = qrr.front().second;
//         qrr.pop();
//         for(auto it:adj[p])
//         {
//             // agar visited nhi ho 
//             if(vis[it]==0)
//             {
//                 vis[it]=1;
//                 qrr.push({it,p});
//             }
//             // agar visited ho lekin us element ko koi or visit kr gya ho
//             else if(q!=it)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;

// }

bool isCycle(vector<int>adj[],int n)
{   // we will maintain a visited record
    vector<int>vis(n,0);
    // ye condition hume connected components tk pahuchati haii 
    for(int i=0;i<n;i++)
     {
        if(!vis[i])
        {
            if(DetectCycle(adj,i,-1,vis))
            // if(Detect_a_cycle(adj,i,n,vis))
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
    adj[v].push_back(u);
}

int main() 
{
    int n=7;
    vector<int> adj[n+1];
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,5,2);
    addEdge(adj,3,6);
    addEdge(adj,3,4);
    addEdge(adj,5,7);
    addEdge(adj,6,7);
    cout<<isCycle(adj,n);
    return 0;
}