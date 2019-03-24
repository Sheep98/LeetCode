#include<iostream>
#include<string>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        if (s.length() == 0)
            return true;
        string s2 = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= '9' && s[i] >= '0'))
                s2.push_back(s[i]);
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                s2.push_back(s[i] - 32);
            }
            continue;
        }
        int l = 0, r = s2.length() - 1;
        while (l < r)
        {
            if (s2[l] == s2[r])
            {
                ++l;
                --r;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "aaaaaaaaaaaa,,,,........         aaaaaaaaaaaaaaaa,,,,,,,aaaaa,a,a";
    Solution so;
    cout << so.isPalindrome(s) << endl;
    system("pause");
    return 0;
}