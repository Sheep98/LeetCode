#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int length = nums.size() ;
        int left = 0;
        int right = length-1;
        int mid = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[right])        //中值小于右值 说明右边是有顺序的
            {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else                                     //左边是有顺序的
            {
                if (nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    while(-1){
        
        for(auto n:v){
            cout << n << " ";
        }
        cout << "cin a number: ";
        cin >> target;
        cout << s.search(v, target) << "\n\n";
        }
    system("pause");
    return 0;
}