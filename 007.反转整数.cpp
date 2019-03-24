#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        int count = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (count > INT_MAX / 10 || (count == INT_MAX / 10 && pop > 7))
                return 0;
            if (count < INT_MIN / 10 || (count == INT_MIN / 10 && pop < -8))
                return 0;
            count = count * 10 + pop;
        }
        return count;
    }
};

int main()
{
    int i, x;
    cout << "输入x:" << endl;
    cin >> x;
    Solution solution;
    cout << endl
         << "x的反转整数为:" << endl;
    cout << solution.reverse(x) << endl;
    system("pause");
    return 0;
}