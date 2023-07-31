#include <bits/stdc++.h>
using namespace std;
class SOLUTION 
{
    // recursive approach of dfs
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col,int arr[],int brr[])
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int tan = row + arr[i];
            int ris = col + brr[i];
            if(tan>=0 && ris>=0 && tan<m && ris<n && !vis[tan][ris] && grid[tan][ris]==1)
            {
                dfs(grid,vis,tan,ris,arr,brr);
            }
        }
    }
public:
// Hume no of one chahiye jo ki boundary connected na ho
    int nr_of_enclaves(vector<vector<int>>grid,int m,int n)
    {
        vector<vector<int>>vis(m,vector<int>(n,0));
        int arr[]={1,0,-1,0};
        int brr[]={0,-1,0,1};
        // boundary elements check krna hai agar value 1 hai or 
        // unvisited hai to uspr dfs call krde
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                dfs(grid,vis,i,0,arr,brr);
            }
            if(!vis[i][n-1] && grid[i][n-1]==1)
            {
                dfs(grid,vis,i,n-1,arr,brr);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                dfs(grid,vis,0,j,arr,brr);
            }
            if(!vis[m-1][j] && grid[m-1][j])
            {
                dfs(grid,vis,m-1,j,arr,brr);
            }
        }
        int count=0;
        // is moment tk humare saare boundary or boundary related 1 hoge
        // vo visit ho chuke honge
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // ab sirf wo 1 count honge jo unvisited honge
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }

};

int main() 
{
 int m,n;
    cout<<"Enter the value of m and n :";
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n,0));
    cout<<"Enter the matrix"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<endl;
    SOLUTION s1;
    int ans=s1.nr_of_enclaves(grid,m,n);
    cout<<ans<<endl;
return 0;
}