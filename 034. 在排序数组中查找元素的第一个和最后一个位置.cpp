#include<iostream>
#include<vector>
using namespace std;
int i = 0;
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target){
        int length=nums.size();
        if(length==1){
            if(nums[0]==target)
                return {0,0};
            else
                return {-1, -1};
        }
        if(length==2){
            if(nums[0]==target&&nums[1]==target)
                return {0, 1};
            else if (nums[0] == target && nums[1] != target)
                return {0, 0};
            else if (nums[0] != target && nums[1] == target)
                return {1, 1};
            else
                return {-1, -1};
        }
        int l = 0;
        int r = length - 1;
        int mid =(r + l) / 2;
        int lhs = -1;
        int rhs = -1;
        while(l<=r){
            mid = (r + l) / 2;
            if(nums[mid]<target){
                l = mid+1;
            }
            else if (nums[mid] > target){
                r = mid-1;
            }
            else{
                cout << mid << endl;
                lhs = mid;
                rhs = mid;
                while(lhs>=0){
                    if(lhs==0&&nums[0]==target)
                        break;
                    if(nums[lhs-1]==target)
                        --lhs;
                    else
                        break;
                }
                while (rhs <=length-1)
                {
                    if (rhs == length-1 && nums[length-1] == target)
                        break;
                    if (nums[rhs + 1] == target)
                        ++rhs;
                    else
                        break;
                }
                break;
            }
        }
        return {lhs, rhs};
    }
};


int main(){
    vector<int> v={1};
    Solution s;
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;
    auto ans = s.searchRange(v, 7);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

    system("pause");
    return 0;
}