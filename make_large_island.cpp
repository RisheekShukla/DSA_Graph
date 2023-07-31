#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{ 
 
public:
    int MaxConnection(vector<vector<int>>& grid)
    {
        int n = grid[0].size();
        // crete DJsets for the elements of whole grid
        DisjointSet ds(n*n);
        // first make disjoints set of the given 1s in grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 )
                {
                    continue;
                }
                // cout<<" $ ";
                // if it is 1
                int num0 = i*n+j;
                int arr[]={0,0,1,-1};
                int brr[]={1,-1,0,0};
                // visiting neighbours
                for(int p=0;p<4;p++)
                {
                    int new_x = i+arr[p];
                    int new_y = j+brr[p];
                    if(new_x>=0 && new_y>=0 && new_x<n && new_y<n && grid[new_x][new_y]==1)
                    {
                        int num1 = new_x*n+new_y;
                        ds.unionBySize(num0,num1);
                    }
                }
            }
        }
        int arr[]={0,0,1,-1};
        int brr[]={1,-1,0,0};
        int mx=0;
        // we traverse the 0s in the grid and if its neighbour is an island then store parent element of it in set
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>st;
                    for(int p=0;p<4;p++)
                    {
                        int new_x = i+arr[p];
                        int new_y = j+brr[p];
                        if(new_x>=0 && new_y>=0 && new_x<n && new_y<n && grid[new_x][new_y]==1)
                        {
                            st.insert(ds.findUPar(new_x*n+new_y));
                        }
                    }
                    // add the neighbouring isalnds to check 
                    // the possibilities of creating the largest island by changing that particular cell
                    int val=0;
                    for(auto it:st)
                    {
                        val += ds.size[it];
                    }
                    mx=max(mx,val+1);
                }
            }
        }

        // what if grid contains all one
        for(int i=0;i<n*n;i++)
        {
            mx = max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};

int main() {

    vector<vector<int>> grid = 
    {
        {1, 1, 0, 1, 1, 0}, 
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, 
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, 
        {0, 0, 1, 1, 1, 0}
    };

    Solution obj;
    int ans = obj.MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}   