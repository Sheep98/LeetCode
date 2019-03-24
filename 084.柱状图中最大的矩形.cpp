 #include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        if(heights.empty())
            return 0;
        int res=INT_MIN;
        for (int i = 0; i < heights.size();++i){
            int left = i,right=i;
            while(left>=0&&heights[i]<=heights[left])
                left--;
            while(right<heights.size()&&heights[i]<=heights[right])
                right++;
            int row = right - left -1;
            if(row*heights[i]>res){
                res = row * heights[i];
            }
        }
        return res;
    }
};

int main(){
    vector<int> v = {2, 1, 5, 6, 2, 3};
    Solution s;
    cout << "the max: " << s.largestRectangleArea(v) << endl;
    system("pause");
    return 0;
}