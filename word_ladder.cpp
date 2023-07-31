#include <bits/stdc++.h>
using namespace std;
class Solution
{ 
 
public:
    int wordLadderLength(string startword,string targetword,vector<string>&wordList)
    { // startword = 'der' & targetword = 'dfs'
      // we have to return the number of steps taken to reach targetword from startword

      // this queue will contain the word and current steps
        queue<pair<string,int>>qrr;
        qrr.push({startword,1});
        
        // set data structure is used here as there must be simplicity
        unordered_set<string>lists(wordList.begin(),wordList.end());
        // if we found any element which exist in set then we will erase it and put it in queue
        lists.erase(startword);
        while(!qrr.empty())
        {
            string word = qrr.front().first;
            int steps = qrr.front().second;
            // if found target then stop
            if(word==targetword)return steps;
            qrr.pop();
            // check [a-->z] over each place
            for(int i=0;i<word.size();i++)
            {
                char org = word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    // if we found any element which exist in set then we will erase it and put it in queue
                    if(lists.find(word)!=lists.end())
                    {
                        lists.erase(word);
                        qrr.push({word,steps+1});
                    }
                }
                // make sure to put the original value back so that it can traverse further more
                word[i]=org;
            }
        }
        return 0;
    }
};
int main() 
{
    
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
return 0;
}