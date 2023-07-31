#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{ 
private:

    vector<int>rank;
    vector<int>parent;

public:

     DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int find_parent(int ele)
    {
        if(ele == parent[ele])
        {
            return ele;
        }
        return find_parent(parent[ele]);
    }

    void unite(int u,int v)
    {
        int u_sup_par = find_parent(u);
        int v_sup_par = find_parent(v);
        if(u_sup_par==v_sup_par)return;
        if(rank[u_sup_par]<rank[v_sup_par])
        {
            parent[u_sup_par]=v_sup_par;
        }
        else if(rank[u_sup_par]>rank[v_sup_par])
        {
            parent[v_sup_par]=u_sup_par;
        } 
        else
        {
            parent[v_sup_par]=u_sup_par;
            rank[u_sup_par]++;
        }
    }
};
int main() 
{
    DisjointSet djt(7);
    djt.unite(1,2);
    djt.unite(2,3);
    djt.unite(4,5);
    djt.unite(6,7);
    djt.unite(5,6);
    djt.unite(3,7);
    if(djt.find_parent(3)==djt.find_parent(7))
    {
        cout<<"Yes they are in a component"<<endl;
    }
    else
    {
        cout<<"No they aren't "<<endl;
    }
    // djt.unite(3,7);

return 0;
}