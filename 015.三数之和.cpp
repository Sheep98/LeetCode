#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int threeSumMulti(vector<int> &A, int target)
    {
        int res = 0,n=A.size();
        map<int, int> m;
        for(auto n:A){
            

        }
        sort(A.begin(), A.end());
        for (int i = 1; i < n - 1;++i){
            int l = 0, r = n - 1;
            while(l<i&&r>i){
                if(A[l]+A[i]+A[r]==target){
                    res++;
                }
            }


        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> v;
    v = solution.threeSum(nums);
    for (auto b = v.begin(); b != v.end(); b++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << (*b)[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}