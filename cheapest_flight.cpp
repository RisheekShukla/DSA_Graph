#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  
    {
        // make the adjacency list
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dist(n,1e9);
        queue<pair<pair<int,int>,int>>qrr;
        // starting from the given source
        qrr.push({{0,src},0});
        dist[src]=0;
        
        while(!qrr.empty())
        {
            // taking each node at a time
           int stops = qrr.front().first.first;
           int node = qrr.front().first.second;
           int dis = qrr.front().second;
           qrr.pop();
            
           if(stops>K)continue;
           
           for(auto it:adj[node])
           {
               int adjnode = it.first;
               int fair = it.second;

               if(stops<=K && dis+fair<dist[adjnode])
               {
                   dist[adjnode]=dis+fair;
                   qrr.push({{stops+1,adjnode},dist[adjnode]});
               }
           }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];

        
    }
};

int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;

    int ans = obj.CheapestFLight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    return 0;
}