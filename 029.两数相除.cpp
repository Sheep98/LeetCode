#include<iostream>
#include<time.h>
using namespace std;

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (dividend == -2147483648 && divisor == -1)
            return 2147483647; //正整数和负整数最大值差1
        bool flag=0;
        if (dividend > 0 ^ divisor > 0)
        {
            flag = 1;
        }
        long long dvd = labs(dividend);//讲这两个计算值转换为正数并传递给long long型
        long long dvs = labs(divisor);
        long long n = 0;//保存结果
        time_t begin = time(NULL);
        while(dvd>=dvs){
            long long temp = dvs;
            long long divide = 1;
            while (dvd >= (temp << 1))
            {
                temp <<= 1;
                divide <<= 1;
            }
            dvd -= temp; //改变被除数的大小
            n += divide;
        }
        time_t end = time(NULL);
        cout << begin << " " << end << endl;
        return (flag) ? (0 - n) : n;
        }
};


int main(){
    Solution s;
    int d=783291849;
    int r=-3;

    cout << r << "/" << d << "="
         << s.divide(d, r) << endl;

    system("pause");
    return 0;
}
