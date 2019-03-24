#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;
        int i = 0,max=0;
        int step = 0,index;
        while(i<nums.size()){
            if(i+nums[i]>=nums.size()-1){
                ++step;
                break;
            }
            max = nums[i];
            index = i + i;
            for (int j = i + 1; j <= nums[i] + i;++j){
                if(nums[j]+j-i>max){
                    max = nums[j] + j - i;
                    index = j;
                }
            }
            ++step;
            i = index;
            max = 0;
        }
        return step;
    }
};

int main(){

    system("pause");
    return 0;
}