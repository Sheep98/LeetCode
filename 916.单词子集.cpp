#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<string> res;
        vector<map<char, int>> vma(A.size());
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A[i].size(); ++j)
            {
                if (vma[i].find(A[i][j]) != vma[i].end())
                {
                    vma[i][A[i][j]]++;
                }
                else
                {
                    vma[i][A[i][j]] = 1;
                }
            }
        }
        map<char, int> m;
        for (int i = 0; i < B.size(); ++i)
        {
            map<char, int> temp;
            for (int j = 0; j < B[i].size(); ++j)
            {
                if (temp.find(B[i][j]) != temp.end())
                {
                    temp[B[i][j]]++;
                }
                else
                {
                    temp[B[i][j]] = 1;
                }
            }
            auto b = temp.begin();
            while (b != temp.end())
            {
                if (m.find((*b).first) != m.end())
                {
                    if (m[(*b).first] < (*b).second)
                    {
                        m[(*b).first] = (*b).second;
                    }
                }
                else
                {
                    m[(*b).first] = (*b).second;
                }
                ++b;
            }
        }
        for (int i = 0; i < A.size(); ++i)
        {
            if (judge(vma[i], m))
            {
                res.push_back(A[i]);
            }
        }

        return res;
    }
    bool judge(map<char, int> &a, const map<char, int> &b)
    {
        auto bg = b.begin();
        while (bg != b.end())
        {
            if (a.find((*bg).first) != a.end())
            {
                if (a[(*bg).first] < (*bg).second)
                    return false;
            }
            else
                return false;
            ++bg;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> A = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> B = {"e", "oo"};
    auto n = s.wordSubsets(A, B);
    for (auto nn : n)
    {
        cout << nn << endl;
    }
    system("pause");
    return 0;
}