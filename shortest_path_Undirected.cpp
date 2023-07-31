// For unit distance
#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
public:
vector<int>shortest_path(int n,int m,vector<vector<int>>&edges)
{
    vector<int>adj[n];
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>dist(n);
    for(int i=0;i<n;i++)dist[i]=1e9;
    int src = 0;
    dist[src]=0;
    queue<int>qrr;
    qrr.push(src);
    while(!qrr.empty())
    {
        int node = qrr.front();
        qrr.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it] = dist[node]+1;
                qrr.push(it);
            }
        }
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        if(dist[i]!=1e9)
        {
            ans[i]=dist[i];
        }
    }
    return ans;

}
 
};
int main() 
{
   int n=9,
        m=10;
    vector<vector<int>>edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    Solution s1;
    vector<int>ans = s1.shortest_path(n,m,edges);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
return 0;
}

