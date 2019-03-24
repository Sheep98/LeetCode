#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int a[9][9] = {0};
        int b[9][9] = {0};
        int c[9][9] = {0};
        for (int i = 0; i < 9;++i){
            for (int j = 0; j < 9;++j){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if(a[i][num]||b[j][num]||c[k][num])
                        return false;
                    a[i][num] = b[j][num] = c[k][num] = 1;
                }    
            }
        }
        return true;
    }
};


int main(){
    vector<vector<char>> board = {{'5', '3', '.', '.', '5', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    bool b;
    b = s.isValidSudoku(board);
    if(b)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    system("pause");
    return 0;
}