#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        //m是宽 n是长
        vector<int> line(m, 0);
        vector<vector<int>> v(n,line);
        for (int i = 0; i < m;++i)
            v[0][i] = 1;
        for (int i = 0; i < n;++i)
            v[i][0] = 1;
        for (int i = 1; i < m;++i){
            for (int j = 1; j < n;++j){
                v[j][i] = v[j][i - 1] + v[j - 1][i];
            }
        }
        return v[n - 1][m - 1];
    }
};

int main(){
    Solution s;
    int m, n;
    m = 23, n = 12;
    cout << "m=" << m << "  n=" << n << endl;
    cout << "unique=" << s.uniquePaths(m, n)<<endl;
    system("pause");
    return 0;
}