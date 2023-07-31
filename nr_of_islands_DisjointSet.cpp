#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int>parent,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find_par(int val)
    {
        if(parent[val]==val)
        {
            return val;
        }
        return parent[val]=find_par(parent[val]);
    }

    void Unite(int u,int v)
    {
        int u_boss = find_par(u);
        int v_boss = find_par(v);
        if(u_boss == v_boss)return;
        if(size[u_boss]<size[v_boss])
        {
            parent[u_boss]=v_boss;
            size[u_boss] += size[v_boss];
        }
        else
        {
            parent[v_boss] = u_boss;
            size[v_boss] += size[u_boss];
        }
    }
};

class Solution
{ 
 
public:
    vector<int>numOfIslands(int n,int m,vector<vector<int>>&operators)
    {
        int count=0;
        int arr[]={0,1,0,-1};
        int brr[]={1,0,-1,0};
        DisjointSet ds(m*n);
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<int>ans;
        // taking each given nodes
        for(auto it:operators)
        {
            int x = it[0];
            int y = it[1];
            int num0 = m*x+y;
            if(grid[x][y]==1)
            {
                ans.push_back(count);
                continue;
            }
                count++;
                grid[x][y]=1;

            // check the neighbours
            for(int i=0;i<4;i++)
            {
                int tan = x + arr[i];
                int rish = y + brr[i];
                int num1=m*tan+rish;
                if(tan>=0 && rish>=0 && tan<n && rish<m && grid[tan][rish]==1 && ds.find_par(num0)!=ds.find_par(num1))
                {
                   ds.Unite(num0,num1);
                    count--;
                }
            }
            ans.push_back(count);
        }

        return ans;

    }
 
};

int main() {

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}