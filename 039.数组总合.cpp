#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    void combin(vector<vector<int>> &ans, vector<int> &candidates, vector<int> item, int target, int start){
        if(target==0){
            ans.push_back(item);
            return;
        }
        if(target<0)
            return;
        for (int i = start; i < candidates.size();i++)
        {
            item.push_back(candidates[i]);
            combin(ans,candidates,item,target-candidates[i],i);
            item.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> item;
        combin(ans, candidates, item, target, 0);
        return ans;
    }
};

int main(){
    vector<int> v = {2, 3, 5};
    Solution s;
    auto a = s.combinationSum(v, 8);
    for (int i = 0; i < a.size();++i)
    {
        cout << "[";
        for(auto b:a[i]){
            cout << b << ",";
        }
        cout <<"]" <<endl;
    }
    system("pause");
    return 0;
}