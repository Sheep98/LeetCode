#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.size() == 1)
            return s;
        string ans;
        int left, right;
        for (int i = 1; i < s.size(); ++i)
        {
            left = i - 1;
            right = i;
            /*
			 *这个地方的坑一定要注意，那就是越界条件在while循环之中也是有先后顺序的，例如
			 防止越界的判断必须要在可能出现越界错误之前！！！之前！！
			 不然就可能出现越界错误
			 while循环 if里面的判断都是如此！！！
			 */
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }

            int paliStart = left + 1, paliEnd = right - 1;
            int paliLen = paliEnd - paliStart + 1;
            if (paliLen > ans.size())
            {
                ans = s.substr(paliStart, paliLen);
            }

            left = i - 1;
            right = i + 1;

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }

            paliStart = left + 1;
            paliEnd = right - 1;
            paliLen = paliEnd - paliStart + 1;
            if (paliLen > ans.size())
            {
                ans = s.substr(paliStart, paliLen);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s;
    while (1)
    {
        cin >> s;
        cout << solution.longestPalindrome(s) << endl;
        //cout << s.size() << endl<<s[1]<<endl;
    }
    system("pause");
    return 0;
}