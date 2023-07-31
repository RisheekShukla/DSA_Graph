#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<int>adj[],int p,vector<int>&vis,int n)
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
            if(!vis[it] && q=='B')
            {
                vis[it]=1;
                colour[it]='R';
                qrr.push({it,'R'});
            }
            else if(!vis[it] && q=='R')
            {
                vis[it]=1;
                colour[it]='B';
                qrr.push({it,'B'});
            }
            else if(vis[it] && q==colour[it])
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
    int n = 9;
    vector<int>adj[n+1];
    vector<int>vis(n,0);
    addEdge(adj,1,2);
    addEdge(adj,3,2);
    addEdge(adj,3,4);
    addEdge(adj,3,5);
    addEdge(adj,5,6);
    addEdge(adj,4,7);
    addEdge(adj,6,7);
    addEdge(adj,7,8);
    addEdge(adj,9,8);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(bipartite(adj,1,vis,n))
            {
                cout<<"Yes it is Bipartite"<<endl;
            }
        else
            {
                cout<<"No it is not Bipartite"<<endl;
            }
        }
    
    }
    return 0;
}