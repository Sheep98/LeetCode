#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        if(length==0||length==1)
            return;
        int i = k % length;
        nums.insert(nums.begin(),nums.end()  - i, nums.end() );
        nums.erase(nums.end() - i, nums.end() );
    }
};

void print(vector<int> &v){
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {1};
    print(v);
    Solution s;
    s.rotate(v, 6);
    print(v);
    //cout << 8 % 6 << endl;`
    system("pause");
    return 0;
}