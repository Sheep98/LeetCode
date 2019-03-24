#include<iostream>
#include<vector>

using namespace std;

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits){
        int c = 1;
        int sum=0;
        for (int i = digits.size() -1; i >= 0;--i){
            sum = digits[i] + c;
            c = sum / 10;
            if(c==0){
                digits[i] == sum;
                return digits;
            }
            else{
                digits[i] == sum%10;
            }
        }
        if(c==1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

void print(vector<int> &v){
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;
}

int main(){
    Solution s;
    vector<int> v = {9};
    print(v);
    s.plusOne(v);
    print(v);
    system("pause");
    return 0;
}