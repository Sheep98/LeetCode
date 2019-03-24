#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        vector<vector<int>> vec(3, vector<int>(3, 0));
        int result = 0;
        for (int i = 0; i < grid.size() - 3;++i){
          for (int j = 0; j < grid[0].size() - 3;++j){
            for (int col = i,ii=0; col < i + 3;++col,++ii){
              for (int row = j,jj=0; row < j + 3;++row,++jj){
                vec[ii][jj] = grid[col][row];
              }
            }
            if(isMagic(vec))
              ++result;
            vec.clear
          }
        }
    }

    bool isMagic(vector<vector<int>> &vec){
      set<int> _s;
      for (int i = 0; i < 3;++i){
        for (int j = 0; j < 3;++j){
          if(_s.find(vec[i][j])!=_s.end()&&vec[i][j]>0&&vec[i][j]<=9){
            _s.insert(vec[i][j]);
          }else{
            return false;
          }
        }
      }
      int num = vec[0][0] + vector[0][1] + vector[0][2];
      if ((vec[2][0] + vec[2][1] + vec[2][2]) != num ||
          (vec[0][0] + vec[0][1] + vec[0][2]) != num ||
          (vec[0][2] + vec[1][2] + vec[2][2]) != num ||)
        return false;
      num -= vec[1][1];
      if ((vec[0][0] + vec[2][2]) != num ||
          (vec[1][0] + vec[1][2]) != num ||
          (vec[2][0] + vec[0][2]) != num ||
          (vec[0][1] + vec[2][1]) != num)
        return false;
      return true;
    }
};

int main(){

    system("pause");
    return 0;
}
