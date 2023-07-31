#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
     vector<int>size,parent;
     public:
     DisjointSet(int n)
     {
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
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
        int gg_u = get_parent(u);
        int gg_v = get_parent(v);
        if(gg_u==gg_v)
        {
            return;
        }
        if(size[gg_u]<size[gg_v])
        {
            parent[gg_u] = gg_v;
            size[gg_v]=size[gg_u]+size[gg_v];
        }
        else
        {
            parent[gg_v]=gg_u;
            size[gg_u] += size[gg_v];
        }
    }

};

class Solution
{ 
 
public:
    int find_prov(int n,vector<vector<int>>&adjmat)
    {
        DisjointSet ds(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adjmat[i][j]==1)
                {
                    ds.unite(i,j);
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(ds.get_parent(i)==i)
            {
                count++;
            }

        }
        return count;
    }
};
int main() 
{
    int n=7;
    // making adjmatrix
    vector<vector<int>>adjmat(n+1,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)adjmat[i][j]=0;
        }
    }
    adjmat[1][2]=1;adjmat[2][1]=1;
    adjmat[2][3]=1;adjmat[3][2]=1;
    adjmat[4][5]=1;adjmat[5][4]=1;
    adjmat[6][7]=1;adjmat[7][6]=1;
    // adjmat[3][4]=1;adjmat[4][3]=1;
    // adjmat[1][6]=1;adjmat[6][1]=1;

    Solution s1;
    int ans = s1.find_prov(n,adjmat);
    cout<<"The number of procinces are : "<<ans<<endl;
    // for(int i=1;i<n+1;i++)
    // {
    //     for(int j=1;j<n+1;j++)
    //     {
    //         cout<<adjmat[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
return 0;
}