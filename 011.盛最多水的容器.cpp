#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        if (height.size() == 2)
            return min(height[0], height[1]);
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            if (min(height[left], height[right]) * (right - left) > water)
                water = min(height[left], height[right]) * (right - left);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return water;
    }
    int min(int i, int j)
    {
        if (i > j)
            return j;
        else
            return i;
    }
};

int main()
{
    Solution solution;
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "the most water: " << solution.maxArea(v) << endl;

    system("pause");
    return 0;
}