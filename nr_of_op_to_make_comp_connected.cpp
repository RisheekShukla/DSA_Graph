
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Disjointset
{
    public:
    vector<int>size,parent;
    Disjointset(int n)
    {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    
    int get_parent(int val)
    {
        if(parent[val]==val)
        {
            return val;
        }
        return parent[val]=get_parent(parent[val]);
    }
    
    void unite(int u,int v)
    {
        int u_gg = get_parent(u);
        int v_gg = get_parent(v);
        if(u_gg == v_gg)
        {
            return;
        }
        if(size[u_gg]<size[v_gg])
        {
            parent[u_gg]=v_gg;
            size[v_gg] += size[u_gg];
        }
        else
        {
            parent[v_gg] = u_gg;
            size[u_gg] += size[v_gg];
        }
    }
    
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) 
    {
        int extraa=0;
        Disjointset ds(n);
        for(auto it:edge)
        {
            int u = it[0];
            int v = it[1];
            if(ds.get_parent(u)!=ds.get_parent(v))
            {
                ds.unite(u,v);
            }
            else
            {
                extraa++;
            }
        }
        int nc=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                nc++;
            }
        }
        if(nc-1<=extraa)
        {
            return nc-1;
        }
        else
        {
            return -1;
        }
    }
};


int main() 
{

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}