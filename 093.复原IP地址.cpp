#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        dfs(res, s, 0, 0);
        return res;
    }
    void dfs(vector<string> &res, string s, int pointNum, int cur)
    {
        if (pointNum == 3)
        {
            string temp(s, cur);
            if (check(temp))
            {
                res.push_back(s);
            }
            return;
        }
        for (int i = 1; i < 4; ++i)
        {
            if (i + cur >= s.size())
                break;
            string temp(s, cur, i);
            if (check(temp))
            {
                s.insert(cur + i, ".");
                dfs(res, s, pointNum + 1, cur + i + 1);
                s.erase(cur + i, 1);
            }
        }
    }
    bool check(string s)
    {
        int i = atoi(s.c_str());
        if (s.size() != 1 && s[0] == '0')
            return false;
        if (i >= 0 && i <= 255)
            return true;
        else if (s.empty())
            return false;
        else
            return false;
    }
};

int main()
{
    Solution s;
    auto a = s.restoreIpAddresses("010010");
    for (auto n : a)
    {
        cout << n << endl;
    }

    system("pause");
    return 0;
}
