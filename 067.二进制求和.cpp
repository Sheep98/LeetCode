#include"bits/stdc++.h"
using namespace std;

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int ia = a.size() - 1,ib=b.size()-1;
        int temp = 0,ans;
        string res;
        while(ia>=0&&ib>=0){
            if(a[ia]=='0'&&b[ib]=='0'){
                res.insert(0, to_string(temp));
                temp = 0;
            }else if(a[ia]=='1'&&b[ib]=='1'){
                res.insert(0, to_string(temp));
                temp = 1;
            }else{
                if(temp==1){
                    res.insert(0, "0");
                }else{
                    res.insert(0, "1");
                }
            }
            --ia;
            --ib;
        }
        while(ia>=0){
            if(a[ia]=='1'){
                if(temp==1){
                    res.insert(0, "0");
                }else{
                    res.insert(0, "1");
                    temp = 0;
                }
            }else{
                res.insert(0, to_string(temp));
                temp = 0;
            }
            --ia;
        }
        while (ib >= 0)
        {
            if (b[ib] == '1')
            {
                if (temp == 1)
                {
                    res.insert(0, "0");
                }
                else
                {
                    res.insert(0, "1");
                    temp = 0;
                }
            }
            else
            {
                res.insert(0, to_string(temp));
                temp = 0;
            }
            --ib;
        }
        if(temp==1)
            res.insert(0, "1");
        return res;
    }
};

int main(){
    Solution s;
    string a = "001";
    string b = "1111";
    cout << s.addBinary(a, b) << endl;
    system("pause");
    return 0;
}