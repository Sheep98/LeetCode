#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution
{
  public:
    bool isValid(string s){
        stack<char> stk;
        int length=s.size();
        stk.push(s[0]);
        for (int i = 1; i < length - 1;i++){
            if(s[i]==stk.top()){
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return stk.empty() ? true : false;
    }
};

int main(){
    Solution s;
    string ss = "{}[]{}";
    cout << s.isValid(ss) << endl;
    system("pause");
    return 0;
}