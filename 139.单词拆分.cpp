#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int slength=s.size();
        int wlength=wordDict.size();
        vector<bool> res(slength+1,false);
        res[0]=true;
        for(int i=1;i<slength+1;++i){
            for(int j=0;j<i;++j){
                if(res[j]==true){
                    //这里是c++11标准的右值引用，比下面的直接拷贝快了近一倍
                    string &&temp=std::move(string(s,j,i-j));
                    //string temp=string(s,j,i-j);
                    bool sig=false;
                    for(auto &n:wordDict){
                        if(temp==n){
                            //cout<<temp<<endl;
                            sig=true;
                            res[i]=true;
                            break;
                        }
                    }
                    if(sig)break;
                }
            }
        }
        return res.back();
    }
};

