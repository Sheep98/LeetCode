#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() == 0)
            return result;
        for (int i = 0; i < strs[0].size(); i++)
        {
            
            int flag = 1;
            for(int j = 1; j < strs.size(); j++)
            {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i])
                {
                    flag = 0;
                    break;
                }
            }
            cout<<i<<" "<<flag<<endl;
            if (flag)
                result+=strs[0][i];
            else 
                return result;
            
        }
        return result;
    }
};
