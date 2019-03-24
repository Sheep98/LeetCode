#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()||matrix[0].empty())return res;
        int size_x=matrix.size();
        int size_y=matrix[0].size();
        int loop = size_x > size_y ? (size_y + 1) / 2 : (size_x + 1) / 2;
        for (int i = 0; i < loop;++i,size_x-=2,size_y-=2)
        {
            for (int col = i; col < i + size_y; col++)
            {
                res.push_back(matrix[i][col]);
            }
            for (int row = i + 1; row < i + size_x; row++)
            {
                res.push_back(matrix[row][i + size_y - 1]);
            }
            //最后一环为一行或一列，则在上面两步之后已经全部输出，直接退出即可
            if (size_x == 1 || size_y == 1)
                break;

            for (int col = i + size_y - 2; col >= i; col--)
            {
                res.push_back(matrix[i + size_x - 1][col]);
            }
            for (int row = i + size_x - 2; row > i; row--)
            {
                res.push_back(matrix[row][i]);
            }
        }


        return res;
        }
    
};

int main(){
    vector<vector<int>> matrix={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    Solution s;
    auto v = s.spiralOrder(matrix);
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}