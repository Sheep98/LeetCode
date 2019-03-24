#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    v = {i + 1, j + 1};
                    cout << i + 1 << " " << j + 1 << endl;
                    return v;
                }
            }
        }
        return v;
    }
};

int main()
{
    vector<int> v = {2, 3, 4, 6, 7};
    Solution solution;
    solution.twoSum(v, 5);
    system("pause");
    return 0;
}