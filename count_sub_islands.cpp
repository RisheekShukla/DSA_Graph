#include<bits/stdc++.h>
using namespace std;
class Solution {

    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&visited,int row,int col,int arr[],int brr[],bool &flag)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        visited[row][col]=1;
        // traversing neighbours
        for(int i=0;i<4;i++)
        {
            int tani = row + arr[i];
            int rish = col + brr[i];

            // agar legal hai to traverse kr with green flag
            if(tani>=0 && rish>=0 && tani<m && rish<n && !visited[tani][rish] && grid1[tani][rish]==1 && grid2[tani][rish]==1)
            {
                dfs(grid1,grid2,visited,tani,rish,arr,brr,flag);
            }
            // lekin agar illegal paya gaya 
            if(tani>=0 && rish>=0 && tani<m && rish<n && !visited[tani][rish] && grid1[tani][rish]==0 && grid2[tani][rish]==1)
            {
                flag = 0;
            }   
        }

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m = grid1.size();
        int n = grid1[0].size();
        int arr[]={1,0,-1,0};
        int brr[]={0,1,0,-1};
        // count ---> nr of islands ko count karega
        int count = 0;
        /* flag ye bataega ki grid2 me hm jis current island ko traverse kr rhe hai 
           agar wo island illegal hai(uska element grid1 ke island ka subset nhi hai) to usko count mt kr */
        bool flag = 0;  
        vector<vector<int>>visi2(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid1[i][j]==1 && grid2[i][j]==1 && !visi2[i][j])
                {
                    // phle to count kro
                    count++;
                    // green flag bhi dedo
                    flag=1;
                    dfs(grid1,grid2,visi2,i,j,arr,brr,flag);
                    // lekin agar traversal ke baad red(0) flag milta hai 
                    if(flag==0)
                    {
                        // count ko hum wapas 1 se decrement kr denge (paap dho lenge)
                        count--;
                    }
                }
            }
        }
        return count;
    }
};

// we have to count sub islands
// sub island means that if there exist an island in grid1 then these islands should contain
// all the cells that make island in grid2
/* grid2 me jitne island ban rhe hai wo grid1 ke islands ke proper subset hone chahiye */
int main()
{
    vector<vector<int>>grid1{{1,0,1,0,1},
                             {1,1,1,1,1},
                             {0,0,0,0,0},
                             {1,1,1,1,1},
                             {1,0,1,0,1}};
    vector<vector<int>>grid2{{0,0,0,0,0},
                             {1,1,1,1,1},
                             {0,1,0,1,0},
                             {0,1,0,1,0},
                             {1,0,0,0,1}};
    Solution s1;
    cout<<s1.countSubIslands(grid1,grid2);

}