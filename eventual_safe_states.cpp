#include <bits/stdc++.h>
using namespace std;
class SOLUTION {
// By simply using dfs
// bool dfs(vector<int>adj[],vector<int>&vis,vector<int>&path_vis,int start,int n,vector<int>&check)
// {
//     vis[start]=1;
//     path_vis[start]=1;
//     check[start]=1;
//     for(auto it : adj[start])
//     {
//         if(!vis[it])
//         {
//             if(dfs(adj,vis,path_vis,it,n,check)==true)
//             {
//                 check[start]=0;
//                 return true;
//             }
//         }
//         else if(path_vis[it]==1)
//         {
//             check[start]=0;
//             return true;
//         }
//     }
//     check[start]=1;
//     path_vis[start] = 0;
//     return false;
// }

void setting(vector<int>adj[],int n,vector<int>newadj[],vector<int>&indegree)
{
    
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            newadj[it].push_back(i);
            indegree[i]++;
        }
    }
}

public:

// By using bfs
vector<int> safe_state_using_bfs(vector<int>adj[],int n)
{
    vector<int>newadj[n];
    vector<int>indegree(n,0);
    setting(adj,n,newadj,indegree);
    queue<int>qrr;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            qrr.push(i);
        }
    }
    vector<int>ans;
    while(!qrr.empty())
    {
        int node = qrr.front();
        qrr.pop();
        ans.push_back(node);
        for(auto it:newadj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                qrr.push(it);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// vector<int> safe_state(vector<int>adj[],int n)
// {
//     vector<int>vis(n,0);
//     vector<int>path_vis(n,0);
//     vector<int>ans;
//     vector<int>check(n,0);
//     for(int i=0;i<n;i++)
//     {
//         if(!vis[i])
//         {
//             dfs(adj,vis,path_vis,i,n,check);
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(check[i]==1)
//         {
//             ans.push_back(i);
//         }
//     }
//     return ans;
// }


};

// void size(vector<int>adj[])
// {
//     cout<<adj->capacity();
// }
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}

int main() 
{

    int n=12;
    vector<int>adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,6);
    addEdge(adj,6,7);
    addEdge(adj,3,5);
    addEdge(adj,5,6);
    addEdge(adj,8,1);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    addEdge(adj,10,8);
    addEdge(adj,11,9);
    SOLUTION s1;
    // vector<int>ans = s1.safe_state(adj,n);
    vector<int>ans = s1.safe_state_using_bfs(adj,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
return 0;
}