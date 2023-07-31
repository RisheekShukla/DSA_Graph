#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int arr[],int brr[])
{
    int m = grid.size();
    int n = grid[0].size();
    vis[i][j]=1;
    
    for(int p=0;p<4;p++)
    {
        int nrow = i+arr[p];
        int ncol = j + brr[p];
        // neighbours check
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='O')
        {
            dfs(grid,vis,nrow,ncol,arr,brr);
        }
    }
    
    
}
// Is problem ki intuition bs yhi h ki border pr agar 'O' ata h to uska dfs nikal do
// Or jo last me grid me unvisited 'O' bache h unko 'X' bana de
vector<vector<char>>surround_zero(vector<vector<char>>&grid,int m,int n)
{
    int arr[]={1,0,-1,0};
    int brr[]={0,1,0,-1};
    vector<vector<int>>vis(m,vector<int>(n,0));
    // hum phla or akhri column check karenge
    for(int i=0;i<m;i++)
    {
            if(!vis[i][0] && grid[i][0] == 'O')
            {
                    dfs(grid,vis,i,0,arr,brr);
            }
            if(!vis[i][n-1] && grid[i][n-1]=='O')
            {
                    dfs(grid,vis,i,n-1,arr,brr);
            }
    }
    // hum phli or akhri row check karenge
    for(int j=0;j<n;j++)
    {
            if(!vis[0][j] && grid[0][j]=='O')
            {
                dfs(grid,vis,0,j,arr,brr);
            }
            if(!vis[m-1][j] && grid[m-1][j]=='O')
            {
                dfs(grid,vis,m-1,j,arr,brr);
            }
    }

    // ab bhi agar koi element 'O' h or visit nhi hua hai 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j]&& grid[i][j]=='O')
            {
                grid[i][j]='X';            
            }
        }
    }
    return grid;
}

int main() 
{
 int m,n;
    cout<<"Enter the value of m and n :";
    cin>>m>>n;
    vector<vector<char>>mat(m,vector<char>(n,'X'));
    cout<<"Enter the matrix"<<endl;;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    vector<vector<char>>ans=surround_zero(mat,m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}