#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        dfs(0, res, nums);
        return res;
    }
    void dfs(int cur,vector<vector<int>> &res,vector<int> nums){
        if(cur==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size();++i){
            if(i!=cur&&nums[i]==nums[cur])
                continue;
            swap(nums[i], nums[cur]);
            dfs(cur + 1, res, nums);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 1,2,2};
    int cnt = 0;
    auto ans = s.permuteUnique(nums);
    for (auto n : ans)
    {
        for (auto nn : n)
        {
            cout << nn << ",";
        }
        ++cnt;
        cout << endl;
    }
    cout << "the cnt: " << cnt << endl;
    system("pause");
    return 0;
}