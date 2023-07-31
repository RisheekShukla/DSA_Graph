#include <bits/stdc++.h>
using namespace std;
#define p 5
#define q 5
int matrix[p][q]={0};

// void bfs(vector<vector<int>>&vis,int i,int j)
// {
//     // is initial element ko 1 kiya
//     vis[i][j]=1;
//     // jaise ki bfs me queue container use hota hai 
//     // is queue me pair format me index store honge
//     queue<pair<int,int>>qrr;
//     qrr.push({i,j}); // initial dala
//     while(!qrr.empty())
//     {
//         int row=qrr.front().first;
//         int col=qrr.front().second;
//         qrr.pop();
//         // bs ab yhi dekhna hai ki iske neighbours me se 1 konsa hai grid me jo ki unvisited ho 
//         for(int delrow=-1;delrow<=1;delrow++)
//         {
//             for(int delcol=-1;delcol<=1;delcol++)
//             {
//                 // ye loops neibour ko vertically horizontally or diagonally search karrenge 
//                 int nrow=row+delrow;
//                 int ncol=col+delcol;
//                 // ye bhi dhyan rkhna hai ki new elements limit me rhe
//                 if(nrow>=0 && nrow<p && ncol>=0 && ncol<q && matrix[nrow][ncol]==1 && !vis[nrow][ncol])
//                 {
//                     vis[nrow][ncol]=1;
//                     qrr.push({nrow,ncol});
//                 }
//             }
//         }
//     }
// }

void dfs(int grid[p][q],vector<vector<int>>&visited,int arr[],int brr[],int row,int col,int m,int n)
    {
        // int m = grid.size();
        // int n = grid[0].size();
        visited[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int new_row = row+arr[i];
            int new_col = col+brr[i];
            if(new_row>=0 && new_col>=0 && new_row<m && new_row<n && !visited[new_row][new_col] && grid[new_row][new_col]=='1')
            {
                dfs(grid,visited,arr,brr,new_row,new_col,m,n);
            }
        }  
    }

void Num_of_island(int x,int y)
{
    // exact grid ke jaisa ek dummy matrix banaya
    vector<vector<int>>vis(x,vector<int>(y,0));
    int count=0;
    int arr[]={0,1,0,-1};
    int brr[]={1,0,-1,0};
    // imagine it like that connected components concept in graph
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(!vis[i][j] && matrix[i][j]==1)
            {   // hr island ka ek initial element call hoga 
                count++; // jitni baar alag alag initials call honge wo humara anser hoga
                // bfs(vis,i,j);
                dfs(matrix,vis,arr,brr,i,j,x,y);
            }
        }
    }
    cout<<count<<endl;
}

int main() 
{
matrix[0][2]=1;
matrix[0][3]=1;
matrix[1][2]=1;
matrix[1][3]=1;
matrix[2][3]=1;
matrix[4][0]=1;
matrix[4][1]=1;
matrix[4][4]=1;

int x=sizeof(matrix)/sizeof(matrix[0]);
int y=sizeof(matrix[0])/sizeof(int);
// cout<<x<<" "<<y<<endl;
// for(int i=0;i<5;i++)
// {
//     for(int j=0;j<5;j++)
//     {
//         cout<<matrix[i][j]<<" ";
//     }
//     cout<<endl;
// }

Num_of_island(x,y);
return 0;
}