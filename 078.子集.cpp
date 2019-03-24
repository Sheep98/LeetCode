#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        if(nums.empty())
            return res;
        DFS(nums, res, temp, 0);
        return res;
    }

    void DFS(const vector<int> &nums, vector<vector<int>> &res, vector<int> &line,int n)
    {
        for (int i = n;i<nums.size();++i)
        {
            line.push_back(nums[i]);
            res.push_back(line);
            DFS(nums, res, line, i + 1);
            line.pop_back();
        }
    }  
};

int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    auto v = s.subsets(nums);
    for(auto n:v){
        for(auto nn:n)
            cout << nn << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}