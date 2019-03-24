#include<iostream>
#include<string>
using namespace std;
//

//没做完 放弃

//
class Solution
{
  public:
    string countAndSay(int n){
        if(n==1)
            return "1";
        string str = "1";
        for (int i = 0; i < n-1;++i){
            str = strFormat(str);
        }
        return str;
    }
    string strFormat(string str){
        int count = 0;
        char e ;
        int i = 0;
        string res;
        while(i < str.size()){
            
            e = str[i];
            while(e==str[i]){
                ++i;
                ++count;
            }
            res+=to_string(count);
            res += e;
            count = 0;
        }
        return res;
    } 
};

int main(){
    Solution s;
    cout << s.countAndSay(2);
    system("pause");
    return 0;
}