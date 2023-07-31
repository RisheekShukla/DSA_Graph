#include <bits/stdc++.h>
using namespace std;
class TAMBIT 
{ 

    void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int row,int col,int &count,int arr[],int brr[])
    {
        int m = grid.size();
        int n = grid[0].size();
        count++;
        visited[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int tani = row + arr[i];
            int rish = col + brr[i];
            if(tani>=0 && rish>=0 && tani<m && rish<n && !visited[tani][rish] && grid[tani][rish]==1)
            {
                dfs(grid,visited,tani,rish,count,arr,brr);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
        {
            int m = grid.size();
            int n = grid[0].size();
            int arr[]={1,0,-1,0};
            int brr[]={0,1,0,-1};
            int main_area = 0;
            vector<vector<int>>visited(m,vector<int>(n,0));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[i][j]&&grid[i][j]==1)
                    {   int area=0;
                        dfs(grid,visited,i,j,area,arr,brr);
                        main_area = max(area,main_area);
                    }
                }
            }
            return main_area;
        }
 
};



int main() 
{
        vector<vector<int>>grid{{1,1}};
    // vector<vector<int>>grid{  {0,0,1,0,0,0,0,1,0,0,0,0,0},
    //                           {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //                           {0,1,1,0,1,0,0,0,0,0,0,0,0},
    //                           {0,1,0,0,1,1,0,0,1,0,1,0,0},
    //                           {0,1,0,0,1,1,0,0,1,1,1,0,0},
    //                           {0,0,0,0,0,0,0,0,1,0,1,0,0},
    //                           {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //                           {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    TAMBIT t1;
    cout<<"The area of biggest island is : " << t1.maxAreaOfIsland(grid);
return 0;
}