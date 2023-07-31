#include <bits/stdc++.h>
using namespace std;
class SOLUTION {

void dfs(vector<vector<int>>&dummy,int grow,int gcol,int storepvs,int newele,int arr[],int brr[],vector<vector<int>>&givenmat)
{
    dummy[grow][gcol]=newele;
    int n = givenmat.size();
    int m = givenmat[0].size();
    // visiting neighbours
    for(int i=0;i<4;i++)
    {
            int newrow = grow+arr[i];
            int newcol = gcol+brr[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && givenmat[newrow][newcol]==storepvs && dummy[newrow][newcol]!=newele)
            {
                dfs(dummy,newrow,newcol,storepvs,newele,arr,brr,givenmat);
            }
    }
}

public:

vector<vector<int>>floodfill(vector<vector<int>>&givenmat,int grow,int gcol,int newele)
{
    // making a dummy grid 
    vector<vector<int>>dummyfill = givenmat;
    // previos value at that place
    int storepvs=givenmat[grow][gcol];
    // conditions for horizontal and vertical neighbours
    int arr[]={0,1,0,-1};
    int brr[]={-1,0,1,0};
    dfs(dummyfill,grow,gcol,storepvs,newele,arr,brr,givenmat);
    return dummyfill;
}

};
int main() 
{
// given grid
vector<vector<int>> givenmat = {{1,1,1},
                                {2,2,0},
                                {2,2,2}};
// given new element and index of element to replace
int grow=2,
    gcol=0,
    newele=3;
SOLUTION s1;
vector<vector<int>>ans = s1.floodfill(givenmat,grow,gcol,newele);
for(auto i:ans)
{
    for(auto j:i)
    {
        cout<<j<<" ";
    }
    cout<<endl;
}
return 0;
}