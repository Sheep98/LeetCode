#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if(matrix.size()==0||matrix[0].size()==0)
            return;
        int col = 0, row = 0;
        for (int i = 0; i < matrix.size();++i){
            if(matrix[i][0]==0)
                col = 1;
        }
        for (int j = 0; j < matrix[0].size();++j){
            if(matrix[0][j]==0)
                row = 1;
        }
        for (int i = 1; i < matrix.size();++i){
            for (int j = 1; j < matrix[0].size();++j){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i){
            for (int j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        if(col){
            for (int i = 0; i < matrix.size();++i)
                matrix[i][0] = 0;
        }
        if(row){
            for (int j = 0; j < matrix[0].size();++j)
                matrix[0][j] = 0;
        }

    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(matrix);
    for(auto n:matrix){
        for(auto n2:n)
            cout << n2 << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}