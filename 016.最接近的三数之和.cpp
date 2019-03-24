#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int length = nums.size();
        int count = 0;
        int min = INT_MAX;
        if (length <= 3)
        {
            for (auto n : nums)
            {
                count += n;
            }
            return count;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = length - 1;
            while (left < right)
            {
                if (abs(target - (nums[i] + nums[left] + nums[right])) < min)
                {
                    min = abs(target - (nums[i] + nums[left] + nums[right]));
                    count = nums[i] + nums[left] + nums[right];
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
                else if (abs(target - (nums[i] + nums[left] + nums[right])) == min)
                {
                    left++;
                }
                else
                    right--;
            }
        }
        return count;
    }
};

int main()
{

    Solution solution;
    vector<int> v = {1, 1, 1, 0};
    cout << "the answer: " << solution.threeSumClosest(v, -100) << endl;

    system("pause");

    return 0;
}