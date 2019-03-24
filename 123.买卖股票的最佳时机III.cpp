#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if(prices.empty())
            return 0;
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int minprices = prices[0];
        for (int i = 1; i < n;++i){
            left[i] = max(prices[i] - minprices, left[i - 1]);
            minprices = min(prices[i], minprices);
        }
        int maxprices = prices.back();
        for (int i = n - 2; i >= 0;--i){
            right[i] = max(right[i + 1],  maxprices-prices[i]);
            maxprices = max(prices[i], maxprices);
        }
        int res = 0 ;
        for (int i = 0; i < n;++i){
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};

int main(){
    vector<int> v = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    Solution s;
    cout<<s.maxProfit(v)<<endl;
    system("pause");
    return 0;
}