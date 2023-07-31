#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
 
public:
    
    vector<int>shortestPath(int v,int e,vector<vector<int>>edges)
    {
        vector<pair<int,int>>adj[v];
        // edges were given in the form [u,v,wt]
        // we will convert it in the form of a adj list ({v,wt})
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
    // using priority queue or min heap  
        // priority_queue <int,vector<int>,greater<int>> pq  // for integer datatype
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq will contain nodes in the form of { distance_travelled_till_node , node }
    
    // using queue
        // queue<pair<int,int>>pq;

    // using set
        set<pair<int,int>>pq;
        vector<int>dist(v);
        // distance initialized with infinity
        for(int i=0;i<v;i++) dist[i]=1e9;
        // src to src dist is 0
        dist[0]=0;
        // pq.push({0,0});
        pq.insert({0,0});
        while(!pq.empty()) 
        {
            // int dis = pq.top().first; // dist travelled till parent
            // int node = pq.top().second;

            // int dis = pq.front().first;
            // int node = pq.front().second;
            
            auto it = *(pq.begin()); // st.begin() represents the address of the first element (hence derefrencing)
            int dis = it.first;
            int node = it.second;
            // pq.pop();
            pq.erase(it);
            for(auto it:adj[node])
            {
                int adjnode = it.first; // child node
                int edw = it.second; // edge wt of child node
                // distance reached till parent + edge wt of child is smaller 
                // then put it in array and push the node with current distance
                if(dis+edw<dist[adjnode])
                {
                    if(dist[adjnode]!=1e9)
                    {
                        pq.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+edw;
                    // pq.push({dist[adjnode],adjnode});
                    pq.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};
int main() 
{
    int V = 8, E = 9;
    vector<vector<int>> edges = {{0, 1, 3},{1, 2, 3},{0, 2, 1},{1, 3, 1},{2, 4, 1},{3, 5, 4},{4, 5, 2},{5, 6, 2},{5, 7, 1}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
return 0;
}