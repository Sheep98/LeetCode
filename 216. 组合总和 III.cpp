#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> vec(k,0);
        dfs(result,vec,k,n,1,0,0);
        return result;
    }

    void dfs(vector<vector<int>> &result,vector<int> vec,int k,int n,int begin,int now,int num){
        if(now==k&&num==n){
            result.push_back(vec);
            vec.clear();
            return;
        }
        if(now>=k)
            return;
        for(int i=begin;i<10;++i){
            vec[now]=i;
            dfs(result,vec,k,n,i+1,now+1,num+i);
        }
        return;
    }
};

int main(){
    Solution s;
    auto n=s.combinationSum3(1,1);
 
    for(auto nn:n){
        for(auto nnn:nn){
            cout<<nnn<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}