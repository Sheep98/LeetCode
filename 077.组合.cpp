#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> a(n,0);
        int temp = 0;
        for(auto &nn:a){
            nn = ++temp;
        }

        vector<vector<int>> res;
        vector<int> line={0};
        DFS(k, 0, res, a, line);
        return res;
    }

    void DFS(const int &k,int ci,vector<vector<int>> &res,const vector<int> &a,vector<int> &line){
        if(ci==k){
            vector<int> temp(line.begin() + 1, line.end());
            res.push_back(temp);
            return;
        }
        for (int i = line.back(); i < a.size();++i){
            line.push_back(a[i]);
            DFS(k, ci+1, res, a, line);
            line.pop_back();
        }
    }
    
};

int main(){
    Solution s;
    auto v = s.combine(4, 2);
    for(auto n:v){
        for(auto nn:n)
            cout << nn << ",";
        cout << endl;
    }

    system("pause");
    return 0;
}