#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        map<int, int> _m;
        for (int i = 0; i < B.size(); ++i)
        {
            _m[B[i]] = i;
        }

        sort(A.begin(), A.end());
        vector<int> res(A.size(), -1);
        map<int, int>::iterator it;
        for (it = _m.begin(); it != _m.end();++it){
            for (auto j = A.begin(); j !=A.end();){
                if((*j)>it->first){
                    res[it->second] = (*j);
                    j = A.erase(j);
                    break;
                }else{
                    j++;
                }
            }
        }
        auto iter = A.begin();
        for (auto &n : res)
        {
            if (n == -1)
            {
                n = *iter;
                iter = A.erase(iter);
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    //[8,2,4,4,5,6,6,0,4,7]
    //[0, 8, 7, 4, 4, 2, 8, 5, 2, 0]
    vector<int> A{8, 2, 4, 4, 5, 6, 6, 0, 4, 7};
    vector<int> B{0, 8, 7, 4, 4, 2, 8, 5, 2, 0};
    auto v = s.advantageCount(A, B);
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}