#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if(matrix.empty())
            return false;
        int col = matrix.size() ;
        int row = matrix[0].size();
        int start = 0, end = col * row -1;
        int mid=0;
        while(start<=end){
            mid = start + (end - start) / 2;
            if(matrix[mid/row][mid%row]<target)
                start = mid + 1;
            else if (matrix[mid / row][mid % row] > target)
                end = mid - 1;
            else return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {
        {1}};
    for (auto n : matrix)
    {
        for (auto n2 : n)
            cout << n2 << " ";
        cout << endl;
    }
    int n=0;
    string ans = s.searchMatrix(matrix, n) ? "existed!" : "No existed";
    cout <<n<<" is "<<ans<< endl;

    system("pause");
    return 0;
}