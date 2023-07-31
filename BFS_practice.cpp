#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int>bfs(vector<int>adj[],int root,int r)
{
    //containers assign krna hai
    vector<int>ans;
    queue<int>q;
    // ??? int r=adj.size(); ???
    int visited[r+1]={0};
    //first node visit krna hai
    visited[root]=1;
    q.push(root); // use queue me dalna hai 
    // hume answer wale vector ki=o fill krna hai jbtk ki hamari queue empty nhi hoti
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // jo node answer me dali hai uske adjacent elements ko visit krke push krna hai
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }

    return ans;
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
    vector<int>ans = bfs(adj,1,n);
    printans(ans);
    return 0;
}