//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        // // my intuition
    //     vector<pair<int,int>>adj[n];
    //     for(auto it:edges)
    //     {
    //         adj[it[0]].push_back({it[1],it[2]});
    //         adj[it[1]].push_back({it[0],it[2]});
    //     }
    //     vector<int>ans[n];
    //     for(int src=0;src<n;src++)
    //     {
    //         vector<int>dist(n,1e9);
    //         dist[src]=0;
    //         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //         pq.push({0,src});
    //         while(!pq.empty())
    //         {
    //             int dis = pq.top().first;
    //             int node = pq.top().second;
    //             pq.pop();
    //             for(auto it:adj[node])
    //             {
    //                 int adjnode = it.first;
    //                 int edgewt = it.second;
    //                 if(dist[node]+edgewt<distanceThreshold && dist[node]+edgewt<dist[adjnode])
    //                 {
    //                     ans[src].push_back(adjnode);
    //                     pq.push({dist[adjnode],adjnode});
    //                 }
    //             }
    //         }
            
    //     }
    //     int t;
    //     int mini = ans[0].size();
    //     for(int i=0;i<n;i++)
    //     {
    //         if(mini>=ans[i].size())
    //         {
    //             mini = ans[i].size();
    //         }
    //     }
    //     for(int i=n-1;i>0;i--)
    //     {
    //         if(mini==ans[i].size())
    //         {
    //            t=i;
    //            break;
    //         }
    //     }
    //     return t;
    // }
    } 
        
};


//{ Driver Code Starts.
int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}

// } Driver Code Ends