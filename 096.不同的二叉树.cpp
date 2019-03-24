#include"bits/stdc++.h"
using namespace std;

class Solution{
public:
    int numTree(int n){
        vector<int> v(n+1 , 1);
        
        for (int i = 2; i <= n;++i){
            for (int j = 1; j <= i;++j){
                v[i] = v[i] + v[i] * v[j-i-1];
            }
        }
        return v[n];
    }
};

int main(){
    Solution s;
    cout << s.numTree(3) << endl;

    system("pause");
    return 0;
}