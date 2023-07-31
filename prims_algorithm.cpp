#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
 
public:
    int spanningTree(int n,vector<vector<int>>adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(n,0);
        // pq contains ({distance,node})
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // if visited then no further process (out of loop)
            if(visited[node]==1)
            {
                continue;
            }
    
            sum = sum + dis;
            visited[node]=1;
            // go for its adjnodes
            for(auto it:adj[node])
            {
                int adjnode = it[0];
                int edgw = it[1];
                if(!visited[adjnode])
                {
                    pq.push({edgw,adjnode});
                }
            }
        }
        return sum;
    }
};

int main() 
{

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for(auto it:edges)
    {
        vector<int>temp(2);
        temp[0]=it[1];
        temp[1]=it[2];
        adj[it[0]].push_back(temp);

        temp[0]=it[0];
        temp[1]=it[2];
        adj[it[1]].push_back(temp);
    }
	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}