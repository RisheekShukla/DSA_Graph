#include <bits/stdc++.h>
using namespace std;
class Solution 
{

public:

    // Topo sort using bfs is called Kahn's Algorithm
    void topo_sort(vector<int>adj[],int n)
    {
        // here concept of indegree used
        // as it represents number of incoming edges on a node
        vector<int>indegree(n,0);
        // way to make indegree
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<indegree[i]<<" ";
        // }

        // queue for bfs algo
        vector<int>ans;
        queue<int>qrr;
        // jin elements ki indegree 0 hai unhe phle push krde
        // unka traversal kisi pvs pr depend nhi karega
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                qrr.push(i);
            }
        }

        while(!qrr.empty())
        {
            // queue me wo element dalte jayenge jinka indegree 0 hota ja rha hai 
            int node = qrr.front();
            qrr.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    qrr.push(it);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
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
    // addEdge(adj,2,3);
    // addEdge(adj,3,1);
    // addEdge(adj,4,0);
    // addEdge(adj,4,1);
    // addEdge(adj,5,0);
    // addEdge(adj,5,2);
    // addEdge(adj,2,3);
    addEdge(adj,5,0);
    addEdge(adj,5,2);
    addEdge(adj,2,0);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,3,1);
    addEdge(adj,1,0);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    
    Solution s1;
    s1.topo_sort(adj,n);
    return 0;
}