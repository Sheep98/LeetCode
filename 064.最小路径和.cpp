#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int i = 1; i < grid.size();++i)
            grid[i][0] = grid[i][0]+grid[i - 1][0];
        for (int i = 1; i < grid[0].size();++i)
            grid[0][i] = grid[0][i] + grid[0][i - 1];
        for (int i = 1; i < grid.size();++i){
            for (int j = 1; j < grid[0].size();++j){
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
    }
};

int main(){
    vector<vector<int>> map = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    cout << "the min value of path:" << s.minPathSum(map) << endl;

    system("pause");
    return 0;
}