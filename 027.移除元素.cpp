#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val){
        int length = nums.size();
        if(length==0)
            return 0;
        if(length==1){
            if(nums[0]==val)
                return 0;
            else
                return 1;
        }
        int left = 0;
        int right = length - 1;
        int num = 0;
        while(left<=right){
            if(left==right&&nums[left]==val){
                ++num;
                break;
            }
            if(nums[right]==val){
                --right;
                ++num;
                continue;
            }
            if(nums[left]==val){
                nums[left++] = nums[right];
                nums[right--] = val;
                ++num;
                continue;
            }
            ++left;
        }
        return length - num;
    }
};

int main(){
    Solution S;
    vector<int> v = {1,2,3};
    auto b = v.begin();
    cout<<"return number: "<<S.removeElement(v, 2)<<endl;
    cout << "return vector:" << endl;
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}