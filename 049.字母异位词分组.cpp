#include"bits\stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        vector<string> s = strs;
        int k = 0;
        for (int i = 0; i < strs.size();++i){
            sort(s[i].begin(), s[i].end());
            if(!m.count(s[i])){
                m[s[i]] = k++;
                res.push_back(vector<string> {});
            }
            res[m[s[i]]].push_back(strs[i]);
        }
        return res;
    }
};

int main(){
    vector<string> v = {"eat", "ate", "tea", "not", "cat", "tac"};
    Solution s;
    auto re = s.groupAnagrams(v);
    for(auto n:re){
        for(auto nn:n){
            cout << nn << ",";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}