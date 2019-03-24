#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        set<string> _s(wordDict.begin(), wordDict.end());
        vector<vector<int>> index(s.size() + 1, vector<int>{});
        index[0].push_back(0);
        for (int i = 1; i < s.size() + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && _s.find(string(s, j, i - j)) != _s.end())
                {
                    dp[i] = true;
                    index[i].push_back(j);
                }
            }
        }
        vector<string> res;
        if (!dp.back())
        {
            return res;
        }
        dfs(res, vector<string>{}, index, s.size(), s);
        return res;
    }
    void dfs(vector<string> &res, vector<string> word, vector<vector<int>> &index, int cur, string s)
    {
        if (cur == 0)
        {
            string line;
            for (int i = word.size() - 1; i > 0; --i)
                line += word[i] + " ";
            line += word[0];
            res.push_back(line);
            return;
        }

        for (auto n : index[cur])
        {
            word.push_back(string(s, n, cur - n));
            dfs(res, word, index, n, s);
            word.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<string> v = {"cat", "cats", "and", "sand", "dog"};
    string str = "catsanddog";
    auto a=s.wordBreak(str,v);
    for(auto n:a){
       cout << n << endl;
    }
    system("pause");
    return 0;
}