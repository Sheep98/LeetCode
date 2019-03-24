#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if(board.empty())
            return false;
        for (int i = 0; i < board.size();++i){
            for (int j = 0; j < board[0].size();++j){
                if(DFS(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>> &board,const string &word,int i,int j,int n){
        if(n==word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if(board[i][j]!=word[n])
            return false;
        char c = board[i][j];
        board[i][j] = ' ';
        bool ret = DFS(board, word, i + 1, j, n + 1) ||
                   DFS(board, word, i -1 , j, n + 1) ||
                   DFS(board, word, i ,  j+1, n + 1) ||
                   DFS(board, word, i ,  j-1, n + 1);
        board[i][j] = c;
        return ret;
    }
    
     
};

int main(){
    vector<vector<char>> board = {{'A','B'}};
    Solution s;
    cout<<(s.exist(board, "BA")==true ?"True" : "False" )<< endl;
   
    system("pause");
    return 0;
}