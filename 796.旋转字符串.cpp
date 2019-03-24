#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size())
            return false;
        return ((A+A).find(B)!=string::npos)?true:false;
    }
};


int main(){
    Solution s;
    cout<<s.rotateString("text","ttex")<<endl;

    system("pause");
    return 0;

}