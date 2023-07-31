#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{ 
    vector<int>size,parent; 
public:
    DisjointSet(int n)
    {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int find_parent(int val)
    {
        if(parent[val]==val)
        {
            return val;
        }
        return (find_parent(parent[val]));
    }

    void unite(int u,int v)
    {
        int u_sup_par = find_parent(u);
        int v_sup_par = find_parent(v);
        if(u_sup_par==v_sup_par)
        {
            return;
        }
        if(size[u_sup_par]<size[v_sup_par])
        {
            parent[u_sup_par]=v_sup_par;
            size[v_sup_par]=size[v_sup_par]+size[u_sup_par];
        }
        else if(size[u_sup_par]>size[v_sup_par])
        {
            parent[v_sup_par] = u_sup_par;
            size[u_sup_par] = size[u_sup_par]+size[v_sup_par];
        }
        // same as else if, just for understanding
        else
        {
            parent[v_sup_par]=u_sup_par;
            size[u_sup_par]=size[u_sup_par]+size[v_sup_par];
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
return 0;
}