#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<int> line(n, 0);
        vector<vector<int>> res(n, line);
        int loops = (n + 1) / 2;
        int size =n,temp=0;
        for (int i = 0; i < loops; ++i, size -= 2)
        {
            for (int row = i; row < size + i;++row){
                res[i][row] = ++temp;
            }
            for (int col = i+1; col < size + i;++col){
                res[col][size+i-1] = ++temp;
            }
            for (int row = size + i - 2; row >= i;--row){
                res[size+i-1][row] = ++temp;
            }
            for (int col = size+i-2; col > i;--col){
                res[col][i] = ++temp;
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a;
    a = s.generateMatrix(1);
  
    for(auto n:a){
        for(auto nn:n){
            cout << setw(3)<<nn << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}