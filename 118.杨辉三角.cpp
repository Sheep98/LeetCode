#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        // int i = 0;
        // while(i<numRows){
        //     vector<int> line(++i, 0);
        //     line[0] = 1;
        //     line[i - 1] = 1;
        //     res.push_back(line);
        // }
        // for (int i = 2; i < numRows;++i){
        //     for (int j = 1; j < i ;++j){
        //         res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        //     }
        // }
        for (int i = 0; i < numRows;++i){
            res[i].resize(i + 1, 1);
            if(i>1){
                for (int j = 1; j < i;++j)
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    auto res=s.generate(6);
    for(auto n:res){
        for(auto nn:n){
            cout << nn << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}