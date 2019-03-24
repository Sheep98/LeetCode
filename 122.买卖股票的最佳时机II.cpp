#include"bits/stdc++.h"
using namespace std;

class Solution
{
   public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        if(prices.empty())
            return res;
        int min = INT_MAX;
        for (int i = 0; i < prices.size()-1;++i){
            if(prices[i]<prices[i+1])
                res += prices[i + 1] - prices[i];
        }
        return res;
    }
};

int main(){
    vector<int> v = {6, 1, 3, 2, 4, 7};
    Solution s;
    cout << s.maxProfit(v) << endl;
    system("pause");
    return 0;
}