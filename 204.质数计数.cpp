#include <iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int countPrimes(int n)
    {
        vector<bool> v(true, n+1);
        int cnt = 0;     //计数器
        for (int i = 2; i < n; i++)
        {
            if (v[i])
            { //如果这个数是质数
                for (int j = i + i; j < n; j += i)
                { //那么该质数的所有倍数都不是质数了
                    v[j] = false;
                }
                cnt++; //计数加一
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.countPrimes(10);
    system("pause");
    return 0;
}