#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
    vector<int>topo(vector<int>adj[],int k)
    {
        vector<int>indegree(k,0);
        for(int i=0;i<k;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>qrr;
        for(int i=0;i<k;i++)
        {
            if(indegree[i]==0)
            {
                qrr.push(i);
            }
        }
        vector<int>tans;
        while(!qrr.empty())
        {
            int node = qrr.front();
            qrr.pop();
            tans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)qrr.push(it);
            }
        }
        return tans;
    }
 
public:

string findOrder(string dict[],int n,int k)
{
    vector<int>adj[k];
    for(int i=0;i<n-1;i++)
    {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(),s2.size());
        for(int j=0;j<len;j++)
        {
            if(s1[j]!=s2[j])
            {
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
        vector<int>topoans = topo(adj,k);
        string ans = "";
        for(auto it:topoans)
        {
            ans = ans + char(it+'a');
        }
        return ans;
}
 
};
int main() 
{
    int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);
    for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

return 0;
}