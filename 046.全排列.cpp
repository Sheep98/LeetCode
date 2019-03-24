#include<vector>
#include<iostream>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        dfs(0, res, nums);
        return res;
    }
    void dfs(int cur,vector<vector<int>> &res,vector<int> &nums){
        if(cur==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size();++i){
            swap(nums[i], nums[cur]);
            dfs(cur + 1, res, nums);
            swap(nums[i], nums[cur]);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    int cnt = 0;
    auto ans=s.permute(nums);
    for(auto n:ans){
        for(auto nn:n){
            cout << nn << ",";
        }
        ++cnt;
        cout << endl;
    }
    cout << "the cnt: " << cnt << endl;
    system("pause");
    return 0;
}