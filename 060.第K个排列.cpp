#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        string res;
        string num = "123456789";
        vector<int> a(9, 1);
        for (int i = 1; i < 9; ++i)
        {
            a[i] = a[i - 1] * i;
        }
        --k;    //这里--K十分重要！因为计算机计算次数是从0——k-1开始的
        for (int i = n; i >= 1; --i)
        {
            int j = k / a[i - 1];
            k %= a[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(3, 3) << endl;

    system("pause");
    return 0;
}