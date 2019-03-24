#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n){
        string path;
        vector<string> result;
        helper(n, n, path, result);
        return result;
    }
    void helper(int left, int right, string path,vector<string> &result){
        if(left==0&&right==0){
            result.push_back(path);
            return;
        }
        if(left!=0)
            helper(left - 1, right, path + "(", result);
        if(right!=0&&left<right)
            helper(left, right - 1, path + ")", result);
    }
};

int main(){
    Solution s;
    vector<string> v=s.generateParenthesis(8);
    for(auto n:v){
        cout << n << endl;
    }
    system("pause");
    return 0;
}