#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
 
public:
 
    int countPaths(int n,vector<vector<int>>&edges)
    {
        // making adj list
        vector<pair<int,int>>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qrr;
        vector<int>ways(n,0);
        vector<int>dist(n,1e9);
        dist[0]=0;
        qrr.push({0,0});
        ways[0]=1;
        while(!qrr.empty())
        {
            int dis = qrr.top().first;
            int node = qrr.top().second;
            qrr.pop();
            for(auto it:adj[node])
            {
                int adjnode = it.first;
                int edgewt = it.second;
                
                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if(dis+edgewt<dist[adjnode])
                {
                    dist[adjnode] = dis + edgewt;
                    qrr.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis+edgewt==dist[adjnode])
                {
                    ways[adjnode] = ways[adjnode]+ways[node];
                }

            }
        }
        return ways[n-1];
    }
};

int main()
{
    // Return the number of ways you can arrive at your 
    // destination in the shortest amount of time
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countPaths(n, edges);

    cout << ans;
    cout << endl;

    return 0;
}