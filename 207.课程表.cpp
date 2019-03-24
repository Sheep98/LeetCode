#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> s(numCourses,0);
        
        vector<vector<bool>> board(numCourses,vector<bool>(numCourses,false));
        for(auto n:prerequisites){
            board[n.second][n.first] = true;
        }
        for (int col = 0; col < numCourses;++col){
            for (int row = 0; row < numCourses; ++row){
                if(board[col][row]==true){
                    s[row]++;
                }
            }   
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (s[i] == 0)
            {
                s[i] = -1;
                for (int j = 0; j < numCourses; ++j)
                {
                    if (board[i][j] == true)
                    {
                        cout << "i:" << i << " j:" << j << endl;
                        s[j]--;
                    }
                }
            }
            for (int k = 0; k < numCourses;++k){
                if(s[k]==0){
                    i = k-1;
                    break;
                }
            }
        }
            
        
        for(auto n:s){
            if(n>0)
                return false;
        }
        return true;
    }
};

class Solution2{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> s(numCourses, 0);       //记录入度的数组
        unordered_map<int, multiset<int>> hash; //这个对应的是图（点对点）
        for (auto n:prerequisites){
            s[n.first]++;
            hash[n.second].insert(n.first);//点到点
        }
        for (int i = 0,j; i < numCourses;++i){
            for (j = 0; j < numCourses;++j){
                if(s[j]==0)
                    break;
            }
            if(j==numCourses)
                return false;
            s[j]--;
            for(auto n:hash[j]){
                s[n]--;
            }
        }
        return true;
    }
};

int main(){
    Solution2 s;
    vector<pair<int, int>> v = {{0, 1}, {0, 2}, {0, 3}};
    cout<<(s.canFinish(4, v)==true?"TRUE":"FALSE");

    system("pause");
    return 0;
}