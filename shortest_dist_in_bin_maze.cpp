#include <bits/stdc++.h>
using namespace std;
class Solution {
 
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) 
    {
        int frow = destination.first;
        int fcol = destination.second;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        // no need of pq as the nodes will be called in a orderd way
        queue<pair<int,pair<int,int>>>qrr;
        // source inserted
        qrr.push({0,{source.first,source.second}});
        int arr[]={0,1,-1,0};
        int brr[]={1,0,0,-1};
        while(!qrr.empty())
        {

            int dist = qrr.front().first;
            int row = qrr.front().second.first;
            int col = qrr.front().second.second;
            qrr.pop();
            // if dest is reached
            if(row==frow && col == fcol)
            {
                return dist;
            }
            distance[row][col]=dist;
            // neighs
            for(int i=0;i<4;i++)
            {
                int tan = row + arr[i];
                int rish = col + brr[i];
                // if bounds + its 1 + is at better distance
                if(tan<n && rish<m && tan>=0 && rish>=0 && grid[tan][rish]==1 && dist+1<distance[tan][rish])
                {
                    distance[tan][rish]=dist+1;
                    qrr.push({distance[tan][rish],{tan,rish}});
                    
                }
            }
        }
        return -1;
    }
};

int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    // src coordinates
    source.first = 0;
    source.second = 1;
    // dest coordinates
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}