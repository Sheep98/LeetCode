#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        int left = 0;
        int right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[left] + nums[right] > target)
            {
                --right;
            }
            else if (nums[left] + nums[right] < target)
            {
                ++left;
            }
            else
            {
                v = {left + 1, right + 1};
                return v;
            }
        }
        return v;
    }
};

int main()
{
    vector<int> v = { 0,2, 3, 5 ,9};
    Solution solution;
    solution.twoSum(v, 5);

    system("pause");
    return 0;
}