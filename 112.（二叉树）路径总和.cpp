#include <iostream>
#include <vector>
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
    bool hasPathSum(TreeNode *root, int sum){  
        if(root==NULL)              //如果传递进来的是空树，则肯定为false
            return false;
        return hasPathSum2(root, sum);    
    } 
    bool hasPathSum2(TreeNode *root, int sum)  //因为要判断是否为空树，所以递归函数另写了，名字也偷懒起了，不要学我哈哈
    {   
        if(root->left==NULL&&root->right==NULL)   //如果该节点是叶子节点（左右都为空）
            return root->val == sum;              //判断是否为目标值并返回结果
        if(root->left==NULL||root->right==NULL){   //如果有一个为非空

            if(root->left!=NULL)
                return hasPathSum2(root->left, sum - root->val);
            else
                return hasPathSum2(root->right, sum - root->val);
        }
        else{                                         //如果两个都不为空，继续递归
            return hasPathSum2(root->left, sum - root->val) || hasPathSum2(root->right, sum - root->val);
        }
    }
};

TreeNode *CreateBiTree(string &s, int &pos)
{
    ++pos;
    TreeNode *t;
    if ((unsigned)pos >= s.size())
        return NULL;
    else
    {
        if (s[pos] == '#')
            t = NULL;
        else
        {
            t = new TreeNode(s[pos] - '0');
            t->left = CreateBiTree(s, pos);
            t->right = CreateBiTree(s, pos);
        }
    }
    return t;
}
TreeNode* createBiTree(string &s){
    int pos=-1;
    return CreateBiTree(s, pos);
}



void midPrint(TreeNode *t)
{
    if (t == NULL)
        return;
    cout << t->val << " ";
    midPrint(t->left);
    midPrint(t->right);
}

int main()
{
    // string s = "#";
    // auto t = createBiTree(s);
    // midPrint(t);
    TreeNode *t2;
    TreeNode*node;
    node = new TreeNode(-2);
    node->left=new TreeNode(-3);
    node->right = NULL;
    t2 = node;
    midPrint(t2);
    Solution solution;
    cout << endl
         << solution.hasPathSum(t2, -5) << endl;
    system("pause");
    return 0;
}