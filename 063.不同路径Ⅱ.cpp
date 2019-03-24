#include"bits/stdc++.h"
using namespace std;
//超出时限了
// class Solution
// {
//   public:
//     int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
//     {
//         int col = obstacleGrid.size();
//         int row = obstacleGrid[0].size();
//         int res=0;
//         DFS(0, 0, col, row, obstacleGrid, res);
//         return res;
//     }
//     bool check(int c, int r, const int &col, const int &row, vector<vector<int>> &map)
//     {
//         if(c>col-1||r>row-1||map[c][r]==1)
//             return false;
//         return true;
//     }
//     void DFS(int c,int r,const int &col,const int &row,vector<vector<int>> &map,int &res)
//     {
//         if(c==col-1&&r==row-1){
//             res++;
//             return;
//         }
//         if(check(c+1,r,col,row,map))
//             DFS(c + 1, r, col, row, map, res);
//         if(check(c,r+1,col,row,map))
//             DFS(c, r + 1, col, row, map, res);
//         return;
//     }

// };

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int>> map(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < obstacleGrid.size();++i){
            for (int j=0; j < obstacleGrid[i].size();++j){
                if(obstacleGrid[i][j]==1)
                    map[i][j] == 0;
                else if(j>0&&i==0)
                    map[i][j] = map[i][j - 1];
                else if(j==0&&i>0)
                    map[i][j] = map[i-1][j];
                else if(i==0&&j==0)
                    map[i][j] = 1;
                else
                    map[i][j] = map[i - 1][j]+map[i][j-1];
            }
        }
        return map.back().back();
    }
};

int main(){
    Solution s;
    vector<vector<int>> map = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "How many why?\n"<<s.uniquePathsWithObstacles(map) << endl;
    system("pause");
    return 0;
}