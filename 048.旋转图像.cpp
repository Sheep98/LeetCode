#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        if(matrix.empty()||matrix[0].size()==1)
            return;
        int length = matrix.size();
        for (int i = 0; i < length;++i){
            for (int j = i+1; j < length;++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < length;++i){
            for (int j = 0; j < length / 2;++j){
                swap(matrix[i][j], matrix[i][length - 1 - j]);
            }
        }
    }
};

void printMatrix(vector<vector<int>> &matrix){
    for(auto n:matrix){
        for(auto nn:n){
            cout << nn << " ";
        }
        cout << endl;
    }

}
int main(){
    vector<vector<int>> matrix = {{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    Solution s;
    cout << "the old matrix: " << endl;
    printMatrix(matrix);
    s.rotate(matrix);
    cout << "\nthe new matrix: " << endl;
    printMatrix(matrix);
    system("pause");
    return 0;
}