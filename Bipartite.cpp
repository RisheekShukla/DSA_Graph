#include <bits/stdc++.h>
using namespace std;

// MY Approach
bool checkrs(vector<int>adj[],vector<int>&vis,int p,int n)
{
    
    vis[p]=1;
    char colour[n];
    colour[p]='R';
    queue<pair<int,char>>qrr;
    qrr.push({p,'R'});
    while(!qrr.empty())
    {
        int p = qrr.front().first;
        char q = qrr.front().second;
        qrr.pop();
        for(auto it:adj[p])
        {
            if(vis[it]==-1 && q=='B')
            {
                vis[it]=1;
                colour[it]='R';
                qrr.push({it,'R'});
            }
            else if(vis[it]==-1 && q=='R')
            {
                vis[it]=1;
                colour[it]='B';
                qrr.push({it,'B'});
            }
            else if(vis[it]==1 && q==colour[it])
            {
                return false;
            }
        }
    }
    return true;
}

// Striver's Approach

// // BFS code
// bool checkbp(vector<int>adj[],vector<int>col,int start,int n)
// {
//     queue<int>qrr;  
//     qrr.push(start); 
//     col[start]=0;  // let color of first node be 0
//     while(!qrr.empty())
//     {
//         int node = qrr.front();
//         qrr.pop();
//         for(auto it:adj[node])
//         {
//          // agar agla node coloured nhi hai to uske color me parent ka oppposite color daal
//             if(col[it]==-1)
//             {
//                 col[it]=!col[node];
//                 qrr.push(it);
//             }
//         // if phle se coloured hai or iska color parent ke jaisa hai to return false
//             else if(col[it]==col[node])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

bool bipartite(vector<int>adj[],int n)
{
    // track record for the colour of nodes 0 or 1
     vector<int>col(n,-1); // -1 means non coloured
     for(int i=0;i<n;i++)
     {
        if(col[i]==-1)
        {
            if(checkrs(adj,col,i,n)==false)
            {
                return false;
            }
        }
     }
     return true;
}

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{
    int n = 4;
    vector<int>adj[n+1];
    // addEdge(adj,1,2);
    // addEdge(adj,3,2);
    // addEdge(adj,3,4);
    // addEdge(adj,3,5);
    // addEdge(adj,4,6);
    // addEdge(adj,5,6);
    // addEdge(adj,6,7);
    // addEdge(adj,7,8);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,3,2);

    // for(int i=1;i<=n;i++)
    // {
        // if(!vis[i])
        // {
            if(bipartite(adj,n))
            {
                cout<<"Yes it is Bipartite"<<endl;
            }
        else
            {
                cout<<"No it is not Bipartite"<<endl;
            }
        // }
    
    // }
    return 0;
}
