#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    bool search(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l<r){
            mid = l + (r - l) / 2;
            if(nums[mid]>target)
                r = mid - 1;
            else if(nums[mid]<target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    Solution s;
    cout << (s.search(nums, 0) ? "True" : "False") << endl;

    system("pause");
    return 0;
}