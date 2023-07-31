#include <bits/stdc++.h>
using namespace std;
// 
void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col,vector<pair<int,int>>&vec,int row0,int col0)
{
    int m = grid.size();
    int n = grid[0].size();
    vis[row][col] = 1;
    // row0,col0 is initial base point from where dfs is called
    // row-row0 and col-col0 ye ek basic format hai mtlb
    // agar same shape ka koi island bn rha hai to uske particular
    // coordinates me se base coordinates subtract karenge to dono 
    // shapes ka vector same ho jaega and set will count them one
    vec.push_back({row-row0,col-col0});
    int arr[]={0,1,-1,0};
    int brr[]={1,0,0,-1};
    for(int i=0;i<4;i++)
    {
        int ta = row + arr[i];
        int ris = col + brr[i];
        if(ta>=0&&ris>=0&&ta<m&&ris<n&&!vis[ta][ris]&& grid[ta][ris]==1)
        {
            dfs(grid,vis,ta,ris,vec,row0,col0);
        }
    }
}
// Islands find krna is a simple task but distinct islands is
// somewhat challenging for that we have to store distinct shapes
int distinct_islands(vector<vector<int>>&grid,int m,int n)
{
    vector<vector<int>>vis(m,vector<int>(n,0));
    // we could use the set data structure 
    // It will contain coordinates of a shape
    set<vector<pair<int,int>>> disti;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                // fill the coordinates of each shape in this vec
                vector<pair<int,int>>vec;
                dfs(grid,vis,i,j,vec,i,j);
                disti.insert(vec);
            }
        }
    }
    return disti.size();
}

int main() 
{
    int m=4,n=5;
    // cout<<"Enter the value of m and n :";
    // cin>>m>>n;
    vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
    // cout<<"Enter the matrix"<<endl;
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cin>>grid[i][j];
    //     }
    // }
    // cout<<endl;
    int ans=distinct_islands(grid,m,n);
    cout<<ans<<endl;
    return 0;
}