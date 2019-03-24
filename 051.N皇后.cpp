#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> sol;
        string str(n, '.');
        for (int i = 0; i < n; ++i)
        {
            sol.push_back(str);
        }
        dfs(n, 0, res, sol);
        return res;
    }
    void dfs(const int &n, int col, vector<vector<string>> &res, vector<string> &sol)
    {
        if (n == col)
        {
            res.push_back(sol);
            return;
        }
        for (int row = 0; row < n; ++row)
        {
            sol[col][row] = 'Q';
            if (isValid(col, row, sol))
            {
                dfs(n, col + 1, res, sol);
            }
            sol[col][row] = '.';
        }
    }
    bool isValid(int &col, int &row, vector<string> &sol)
    {
        for (int i = 0; i < col; ++i)
        {
            if (sol[i][row] == 'Q')
                return false;
        }
        for (int i = col - 1, j = row - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (sol[i][j] == 'Q')
                return false;
        }
        for (int i = col - 1, j = row + 1; i >= 0 && j < sol.size(); i--, j++)
        {
            if (sol[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    auto res=s.solveNQueens(4);
    cout << res.size();

    system("pause");
    return 0;
}