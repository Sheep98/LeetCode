#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
        for (auto n : nums)
        {
            if (n == 0)
                cnt_0++;
            else if (n == 1)
                cnt_1++;
            else
                cnt_2++;
        }
        for (auto &n : nums)
        {
            if (cnt_0-- > 0)
                n = 0;
            else if (cnt_1-- > 0)
                n = 1;
            else
                n = 2;
        }
    }
};