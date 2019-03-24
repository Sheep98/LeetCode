#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<string> board;
        string str(n, '.');
        for (int i = 0; i < n;++i){
            board.push_back(str);
        }
        dfs(board, 0, n, count);
        return count;
    }
    void dfs(vector<string> &sol,int col,const int &n,int &count){
        if(col==n){
            ++count;
            return;
        }
        for (int row = 0; row < n;++row){
            sol[col][row] = 'Q';
            if(isValid(sol,row,col)){
                dfs(sol, col+1, n, count);
            }
            sol[col][row] = '.';
        }
    }
    bool isValid(vector<string> &sol,int &row,int &col){
        for (int i = 0; i < col;++i){
            if(sol[i][row]=='Q')
                return false;
        }
        for (int i = col - 1, j = row - 1; i >= 0 && j >= 0;--i,--j){
            if (sol[i][j] == 'Q')
                return false;
        }
        for (int i = col - 1, j = row + 1; i >= 0 && j < sol.size(); --i, ++j)
        {
            if (sol[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.totalNQueens(4) << endl;

    system("pause");
    return 0;
}