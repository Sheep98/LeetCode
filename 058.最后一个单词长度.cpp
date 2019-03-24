#include<iostream>
using namespace std;

class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        int length = s.size();
        int right, left;
        for (int i = length - 1; i >= 0; --i)
        {
            if(s[i]<='z'&&s[i]>='a'||s[i]<='Z'&&s[i]>='A'){
                right = i;
                left = right;
                while(left>=0){
                    if (s[left] <= 'z' && s[left] >= 'a' || s[left] <= 'Z' && s[left] >= 'A')
                    {
                        left--;
                    }
                    else
                        break;
                }
                return right - left;
            }
        }
        return 0;
    }
};

int main(){
    string s = "Hello World            ";
    Solution ss;
    cout << ss.lengthOfLastWord(s) << endl;
    system("pause");
    return 0;
}