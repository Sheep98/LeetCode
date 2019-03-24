#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int r = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (r < 2 || nums[r - 2] != nums[i])
                nums[r++] = nums[i];
        return r;
    }
};

int main(){
    Solution s;
    vector<int> v = { 1, 1, 1, 2, 2, 3};
    auto a=s.removeDuplicates(v);
    for(auto n:v){
        if(a==0)
            break;
        cout << n << " ";
        a--;
    }
    cout << endl;
    system("pause");
    return 0;
}