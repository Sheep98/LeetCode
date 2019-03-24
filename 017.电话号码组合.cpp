#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    string s[10] = {"",
                    "",
                    "abc",
                    "def",
                    "ghi",
                    "jkl",
                    "mno",
                    "pqrs",
                    "tuv",
                    "wxyz"};
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        string s = "";
        dfs(0, res, digits, s);
        return res;
    }
    void dfs(int n, vector<string> &res,string &digits,string &str)
    {
        if(n==digits.size()){
            res.push_back(str);
            return;
        }
        for (auto x:s[digits[n]-'0'])
        {
            str.push_back(x);
            dfs(n + 1, res, digits, str);
            str.pop_back();
        }
    }
};

int main(){
    Solution s;
    string a = "23";
    auto o = s.letterCombinations(a);
    for(auto n:o){
        cout << n << endl;
    }
    system("pause");
    return 0;
}
