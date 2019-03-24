#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        if(length==1)
            return nums[0];
        //int ans = 0;
        sort(nums.begin(),nums.end());
        auto f = nums.begin()+1;
        auto s = nums.begin();
        while(f!=nums.end()){
            if(*f==*s){
                f+=2;
                s+=2;
            }
            else
            {
                return *s;
            }
        }
        return *s;
    }
};

int main(){
    vector<int> v = {2,2,1};
    Solution s;
    cout <<"answer: "<<s.singleNumber(v) << endl;

    system("pause");
    return 0;
}