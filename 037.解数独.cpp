#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board){
        s(board);
    }
private:
    bool s(vector<vector<char>> &board){
        int row = 0,col=0;
        if(!hasNullPoint(board,row,col))
            return true;
        for (int i = 1; i < 10;++i){
            board[col][row] = (char)(i + '0');
            if(hasRepPoint(board,row,col)){
                if(s(board))
                    return true;
            }
            board[col][row] = '.';
        }
        return false;
    }
    bool hasNullPoint(vector<vector<char>> &board,int &row,int &col){
        for (int i = 0; i < 9;++i){
            for (int j = 0; j < 9;++j){
                if(board[i][j]=='.'){
                    row = j;
                    col = i;
                    return true;
                }
            }
        }
        return false;
    }
    bool hasRepPoint(vector<vector<char>> &board, int &row, int &col){
        for (int i = 0; i < 9;++i){
            if(i!=col&&board[i][row]==board[col][row])
                return false;
        }
        for (int j = 0; j < 9;++j){
            if(j!=row&&board[col][j]==board[col][row])
                return false;
        }
            for (int i = (col / 3) * 3; i < (col / 3) * 3 + 3; ++i)
            {
                for (int j = (row / 3) * 3; j < (row / 3) * 3 + 3; ++j)
                {
                    if ((i != col || j != row) && board[col][row] == board[i][j])
                        return false;
                }
            }
        return true;
    }
};

void printBoard(vector<vector<char>> &b){
    for (int i = 0; i < b.size();++i){
        cout << "----+---+---+---+---+---+---+---+----"<<endl<<"|";
        for (int j = 0; j < b[0].size(); ++j)
        {
            switch (b[i][j])
            {
            case '.':
                cout << "   ";
                break;
            default:
                cout << " "<<b[i][j]<<" ";
                break;
            }
            cout << "|";
        }
        cout<<endl;
    }
    cout << "----+---+---+---+---+---+---+---+----" << endl;
} 
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    printBoard(board);
    cout << endl;
    Solution s;
    s.solveSudoku(board);
    printBoard(board);
   
    system("pause");
    return 0;
}