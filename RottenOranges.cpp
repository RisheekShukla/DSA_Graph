#include <bits/stdc++.h>
using namespace std;
// we will use bfs as same distance orange become rotten at same time
int bfs_simp(vector<vector<int>>&grid)
{
    int arr[]={0,1,-1,0};
    int brr[]={1,0,0,-1};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    int count=0; // total number of fresh oranges
    queue<pair<pair<int,int>,int>>qrr; // queue contains {{row,col},time}
    // ab grid ke saare rotten oranges ko queue me dalo at time == 0
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                qrr.push({{i,j},0});
                visited[i][j]=2;
            }
            // counting fresh oranges
            if(grid[i][j]==1)
            {
                count++;
            }
        }
    }
    // initial time
    int tm=0,
        cnt=0; // ye count karga ki ham kitne elements ko badala hai jo ki 1 the
    // bfs's Seasonal statement
    while(!qrr.empty())
    {
        // phle teeno cheeze nikal li
        int p = qrr.front().first.first;
        int q = qrr.front().first.second;
        int r = qrr.front().second;
        qrr.pop();
        tm = max(tm,r); // ye hr baar time ko update kr rha hai uske bade number se
        // checking 4 neighbours
        for(int i=0;i<4;i++)
        {
            int nrow = p + arr[i];
            int ncol = q + brr[i];
            // agar mil gya to queue me daal do or 
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && visited[nrow][ncol]==0 && grid[nrow][ncol]==1)
            {
                qrr.push({{nrow,ncol},tm+1});
                visited[nrow][ncol] = 2;
                cnt++;
            }
        }        
    }
    // agar humare nr of 1 != jitne element bache h 
    if(count!=cnt)
    {
        return -1;
    }
    else
    {
        return tm;
    }
}

int main() 
{
vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
cout<<"Time is : "<<bfs_simp(grid)<<endl;
return 0;
}