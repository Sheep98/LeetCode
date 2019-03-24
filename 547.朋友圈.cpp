#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int findCircleNum(vector<vector<int>> &M)
    {
        vector<bool> points(M.size(), true);
        int result = 0,len=M.size();
        bool sign = false;
        int i = 0;
        while(true){
            if(!points[i])
                continue;
            if(i==len){
                break;
            }
            DP(M, points, i);
            ++result;
            ++i;
        }
        return result;
    }

    void DP(vector<vector<int>> &M, vector<bool> &points, int index)
    {
        for (int i = 0; i < M.size();++i){
            if(points[i]&&M[index][i]==1){
                points[i] = false;
                DP(M, points, i);
            }
        }
        return;
    }
};

int main()
{
    system("pause");
    return 0;
}
