#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root){

    }
};


TreeNode* CreateBiTree(string &s,int &pos){
    ++pos;
    TreeNode *t;
    if ((unsigned)pos >= s.size())
        return NULL;
    else{
        if(s[pos]=='#'){
            t = NULL;
        }
        else{
            t = new TreeNode(s[pos] - '0');
            t->left = CreateBiTree(s,pos);
            t->right = CreateBiTree(s, pos);
        }
    }
    return t;
}

TreeNode* createBiTree(string &s){
    int pos = -1;
    return CreateBiTree(s, pos);
}

void midPrint(TreeNode *t){
    if(t==NULL)
        return;
    cout<<t->val<<" ";
    midPrint(t->left);
    midPrint(t->right);
}

int main(){
    string s = "123##4##24##3##";
    auto t=createBiTree(s);
    midPrint(t);

    Solution solution;

    system("pause");
    return 0;
}