#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> matrix) {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        vector<vector<int>> vec(matrix.size(),vector<int>(matrix[0].size(),1));
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='0')
                    vec[i][j]=0;
            }
        }
        
        int up,left,up_left,res=-1;
        for(int i=0;i<vec.size();++i){
            for(int j=0;j<vec[0].size();++j){
                if(vec[i][j]==0)
                    continue;
                if(i>0)up=vec[i-1][j];
                else up=0;
                if(j>0)left=vec[i][j-1];
                else left=0;
                if(i>0&&j>0)up_left=vec[i-1][j-1];
                else up_left=0;
                vec[i][j]=1+min(up,left,up_left);  
                if(vec[i][j]>res)
                    res=vec[i][j];
            }
        }
        if(res==-1)
            return 0;
        return res*res;
    }

    int min(int a,int b,int c){
        return (a<b?b=a:b)<c?b:c;
    }
};

int main(){
    Solution s;
    cout<<s.maximalSquare(vector<vector<char>>{{'0'}});
    system("pause");
    return 0;
}