#include"bits/stdc++.h"
using namespace std;
/*
主要思路： 先将数值N中的每个数字独立存储并排序为list，长度记作n；在2的幂中找出长度为n的所有数值，并同样对每个数字存储排序,得到list2，判断list与list2是否逐位相等
*/
class Solution
{
  public:
    bool reorderedPowerOf2(int N)
    {
        if(N==0)
            return true;
        vector<int> list1;
        while(N!=0){
            list1.push_back(N % 10);
            N /= 10;
        }

        sort(list1.begin(), list1.end());
        // for(auto n:list1){
        //     cout << n << " ";
        // }
        // cout << endl;


        int bigSize = 10;
        for (int i = 1; i < list1.size();++i){
            bigSize *= 10;
        }
        int smallSize = bigSize / 10;

        //cout << "bigSize:" << bigSize << " smallSize:" << smallSize << endl;

        vector<int> list2;
        int a = 2;
        while(1){
            if(a>smallSize&&a<bigSize){
                list2.push_back(a);
                a *= 2;
            }else if(a<smallSize){
                a *= 2;
            }else{
                break;
            }
        }
        
        // for(auto n:list2){
        //     cout << n << endl;
        // }

        vector<int> list3;
        for (int i = 0; i < list2.size();++i){
            while(list2[i]!=0){
                list3.push_back(list2[i] % 10);
                list2[i] /= 10;
            }
            sort(list3.begin(), list3.end());
            // for(auto n:list3){
            //     cout << n << " ";
            // }
            // cout << endl;
            if(list1==list3){
                return true;
            }
            list3.clear();
        }
        return false;
    }
};

int main(){
    Solution solution;
    cout << (solution.reorderedPowerOf2(2) == true ? "Yes" : "No") << endl;
    system("pause");
    return 0;
}