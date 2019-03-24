#include <limits.h>
#include <iostream>
#include <string>
using namespace std;

class Solution{
    public :
        int myAtoi(string str){
            long long res = 0; // string could be greater than  max long long ;
int i = 0;
bool sign = true;

// 1) step trim out whitespace;
while (str[i] == ' ' && i < str.length())
{
    i++;
}

// 2) deal with sign;
if (str[i] == '+' || str[i] == '-')
{
    sign = (str[i] == '+') ? true : false;
    i++;
}

// 3) compute value;
while (i < str.length())
{
    //compute current value;
    if (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        if (res - INT_MAX >= 1)
        { //overflow;
            break;
        }
        i++;
    }
    else
    {
        break;
    }
}

if (res - INT_MAX >= 1)
{
    if (sign)
    {
        return INT_MAX;
    }
    return INT_MIN;
}

res = sign ? res : (-1) * res;
return res;
}
}
;

int main(){
    string s = "12132421";
    Solution so;
    cout << so.myAtoi(s) << endl;
    system("pause");
    return 0;
}