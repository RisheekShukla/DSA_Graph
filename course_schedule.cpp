#include <bits/stdc++.h>
using namespace std;
class course 
{ 
 
public:
    // Question tells us to check or find traversals such that prerequisite course should be studied first
    bool topo_sort(vector<int>preq[],int n)
    {
        // Using Kahn's Algorithm
        // making indegree 
         vector<int>indegree(n,0);
         for(int i=0;i<n;i++)
         {
            for(auto it:preq[i])
            {
                indegree[it]++;
            }
         }
         queue<int>qrr;
         int cnt=0;
         // putting nodes with indegree 0 in queue
         for(int i=0;i<n;i++)
         {
            if(indegree[i]==0)
            {
                qrr.push(i);
            }
         }
         while(!qrr.empty())
         {
            cnt++;
            int node = qrr.front();
            qrr.pop();
            for(auto it:preq[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    qrr.push(it);
                }
            }
         }
         if(cnt==n)
         {
            return false;
         }
         else
         {
            return true;
         }
    }
};

void addEdge(vector<int>preq[],int u,int v)
{
    preq[v].push_back(u);
}

    int main() 
{
     int n=6;
    vector<int>preq[n];
    addEdge(preq,2,3);
    addEdge(preq,3,1);
    // addEdge(preq,1,2);
    addEdge(preq,4,0);
    addEdge(preq,4,1);
    addEdge(preq,5,0);
    addEdge(preq,5,2);
    course s1;
    if(s1.topo_sort(preq,n))
    {
        cout<<"No we cant order that"<<endl;
    }
    else
    {
        cout<<"Yes we can order that"<<endl;
    }
return 0;
}