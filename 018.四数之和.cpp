// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
// 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
// 注意： 答案中不可以包含重复的四元组
#include<iostream>
#include<vector>
#include<algorithm>
    using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        int length = nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        if(length<4)
            return ans;
        if(length==4){
            if(nums[0]+nums[1]+nums[2]+nums[3]==target){
                for (int i = 0; i < 4;++i){
                    arr.push_back(nums[i]);
                }
                ans.push_back(arr);
            }
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length;++i){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for (int j = i + 1; j < length;++j){
                 if(j>i+1&&nums[j]==nums[j-1])
                     continue;
                int left = j + 1;
                int right = length - 1;
                while(left<right){
                    if(nums[i]+nums[j]+nums[right]+nums[left]==target){
                        arr.clear();
                        arr.push_back(nums[i]);
                        arr.push_back(nums[j]);
                        arr.push_back(nums[left]);
                        arr.push_back(nums[right]);
                        ans.push_back(arr);
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1])
                            ++left;
                        while (left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                    else if (nums[i] + nums[j] + nums[right] + nums[left] > target){
                        --right;
                        while (left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                    else{
                        ++left;
                        while(left < right &&nums[left] == nums[left - 1])
                            ++left;
                    }
                }

            }
        }
        return ans;
    }
}; 

int main(){
    Solution solution;
    vector<int> v = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> a;
    a = solution.fourSum(v, 0);
    for(auto n:a){
        for (int i = 0; i < 4;i++){
            cout << n[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}