#include <bits/stdc++.h>
using namespace std;
class Solution
{ public:
    vector<vector<string>>finDsequenceS(vector<string>&list,string sw,string tw)
    {
        // use set for easier deletion and less complexity
        unordered_set<string>wordlist(list.begin(),list.end());

        // queue will store the word in sequence
        queue<vector<string>>qrr;
        // push the starting word
        qrr.push({sw});

        // we need a vector to store used words
        vector<string>used;
        used.push_back(sw);
        int level=0;
        vector<vector<string>>ans;
        while(!qrr.empty())
        {
             vector<string>vec=qrr.front();
             qrr.pop();
             

            // when the whole level is traversed then delete the word from set
             if(vec.size()>level)
             {
                level++;
                for(auto it:used)
                {
                    wordlist.erase(it);
                }
             }
            // queue me current vector ka last woed lena hai
             string word = vec.back();
             // agar target word hai
             if(word==tw)
             {
                if(ans.size()==0)
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size())
                {
                    ans.push_back(vec);
                }
             }
             // nhi hai to us word se koi transformed word banao
             for(int i=0;i<word.size();i++)
             {
                char orig = word[i];
                for(char ch = 'a';ch<'z';ch++)
                {
                    word[i]=ch;
                    if(wordlist.count(word)>0)
                    {
                        vec.push_back(word);
                        qrr.push(vec);
                        used.push_back(word);
                        vec.pop_back();

                    }
                }
                word[i]=orig;
             }
        }
        return ans;
    }
 
};
int main() 
{
    vector<string>list={"des","der","dfr","dgt","dfs"};
    string startword="der";
    string targetword = "dfs";
    Solution s1;
    vector<vector<string>>ans = s1.finDsequenceS(list,startword,targetword);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<" "<<ans[i][j];
        }
        cout<<" ]"<<endl;
    }
return 0;
}