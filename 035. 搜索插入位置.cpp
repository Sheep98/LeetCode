#include<iostream>
#include<vector>

using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target){
        int n=0;
        int length = nums.size();
        if(nums[0]==target)
            return 0;
        while(n<length&&nums[n]<target){
            if(nums[n]==target)
                break;
            n++;
        }
        return n;
    }
};

int main(){
    vector<int> v = {1,7};
    Solution s;
    cout << s.searchInsert(v, 8) << endl;
    system("pause");
    return 0;
}