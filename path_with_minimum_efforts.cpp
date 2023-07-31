#include <bits/stdc++.h>
using namespace std;
class Solution
{
 public: 
 int min_efforts(vector<vector<int>>&grid)
 {
    // A route’s effort is the maximum absolute difference in heights between two consecutive cells of the route.
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>qrr;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>diff(m,vector<int>(n,1e9));
    diff[0][0]=0;
    qrr.push({0,{0,0}}); // pushed left-topmost cell
    int arr[]={1,0,-1,0};
    int brr[]={0,1,0,-1};
    
    while(!qrr.empty())
    {
        int i_diff = qrr.top().first; // difference till now
        int row = qrr.top().second.first;
        int col = qrr.top().second.second;
        qrr.pop();
        // In queue if it finally reached right-bottom most cell 
        if(row == m-1 && col == n-1)
        {
            return i_diff;
        }
        for(int i=0;i<4;i++)
        {
            // neighbours
            int tani = row + arr[i];
            int rish = col + brr[i];
            // bounds
            if(tani>=0 && rish>=0 && tani<m && rish<n)
            {
                // calculating absolute difference b/w two connected cells 
                int c_diff = abs(grid[tani][rish]-grid[row][col]);
                // check whether it is more than the pvs one (max it out)
                int real = max(c_diff,i_diff);
                // if it is better than the pvs effort then update it and push it in queue
                if(real<diff[tani][rish])
                {
                    diff[tani][rish] = real ;
                    qrr.push({real,{tani,rish}});
                }
            }
        }

    }
    return 0;
 }
 
};
int main() 
{
    vector<vector<int>>grid = {{1,2,2},{3,8,2},{5,3,5}};
        Solution s1;
        int ans = s1.min_efforts(grid);
        cout<<ans<<endl;
    
return 0;
}