#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if(nums1.empty()){
            return singleFindMedianSortedArrays(nums2);
        }
        else if (nums1.empty()){
            return singleFindMedianSortedArrays(nums1);
        }
        else{
            vector<int> nums;
            nums.resize(nums1.size() + nums2.size());
            merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),nums.begin());
            cout << "new size(): " << nums.size() << endl;
            if(nums.size()%2==1){
                return nums[nums.size() / 2];
            }
            else{
                return singleFindMedianSortedArrays(nums);
            }
        }
    }
    double singleFindMedianSortedArrays(vector<int> &nums){
        int length = nums.size();
        if(length%2==1){    //是奇数
            return nums[length / 2];
        }
        else{
            return returnDouble(nums[length / 2-1], nums[length / 2]);
        }
    }
    double returnDouble(int n1,int n2){
        if ((n1 % 2 == 1 && n2 % 2 == 1) || (n1 % 2 != 1 && n2 % 2 != 1))
        {
            return (n1 + n2) / 2;
        }
        else{
            return (n1 + n2) / 2 + 0.5;
        }
    }
};

int main(){
    Solution s;
    vector<int> v = {};
    vector<int> v2 = {2};
    cout << s.findMedianSortedArrays(v, v2) << endl;

    system("pause");
    return 0;
}