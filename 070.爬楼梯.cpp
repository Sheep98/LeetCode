#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int climbStairs(int n)
    {
        if(n<=0)
            return -1;
        if(n<=2){
            return n;
        }
        vector<int> arr(n,1);
        arr[1] = 2;
        for (int i = 2; i < n;++i){
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr.back();
    }
};

int main(){
    Solution s;

    system("pause");
    return 0;
}