#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    bool checkRecord(string s)
    {
        int Anum = 0, Lnum = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'A')
                ++Anum;
            if (s[i] == 'L')
                ++Lnum;
            else
                Lnum = 0;
            if (Anum > 1 || Lnum > 2)
                return false;
        }

        return true;
    }
};

int main()
{
    system("pause");
    return 0;
}