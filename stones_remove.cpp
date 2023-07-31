#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int>parent,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int get_par(int val)
    {
        if(parent[val]==val)
        {
            return val;
        }
        return parent[val]=get_par(parent[val]);
    }

    void unite(int u,int v)
    {
        int u_boss = get_par(u);
        int v_boss = get_par(v);
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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) 
    {
        int max_r=0;
        int max_c=0;
        for(auto it:stones)
        {
            max_r = max(max_r,it[0]);
            max_c = max(max_c,it[1]);
        }
        DisjointSet ds(max_r+max_c+1);
        set<int>st;
        for(auto it:stones)
        {
            int row_node = it[0];
            int col_node = it[1]+max_r+1;
            ds.unite(row_node,col_node);
            st.insert(row_node);
            st.insert(col_node);
        }
        int comp=0;
        for(auto it:st)
        {
            if(ds.get_par(it)==it)
            {
                comp++;
            }
        }
        return n-comp;
    }
};

int main() {

    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2},
        {1, 3}, {3, 1},
        {3, 2}, {4, 3}
    };

    Solution obj;
    int ans = obj.maxRemove(stones,n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}