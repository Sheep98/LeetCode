#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        for (int i = 2; i < triangle.size();++i){
            for (int j = 0; j < triangle[i].size();++j){
                if (j == 0){
                    triangle[i][j] = triangle[i][j] + min(triangle[i - 1][0], triangle[i - 1][1]);
                }
                else{
                    triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j -1]);
                }
            }
        }
        int res = INT_MIN;
        for(auto n:triangle.back()){
            if(n>res)
                res = n;
        }
        if(triangle.size()==1)
            return triangle[0][0];
        return res + triangle[0][0];
    }
};

int main(){
    vector<int> line1 = {-1};
    vector<int> line2 = {3,2};
    vector<int> line3 = {-3,1,-1};
    Solution s;
    
    system("pause");
    return 0;
}