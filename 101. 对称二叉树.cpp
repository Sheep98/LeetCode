#include<iostream>
#include<vector>
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
    bool isSymmetric(TreeNode *root)
    {
        if(root==NULL)return true;
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *l, TreeNode *r)  //两个节点分别对比，为了方便简写成l和r
    {
        if(l==NULL&&r==NULL)    //如果左右节点都为空，则返回true
            return true;
        if(l==NULL||r==NULL)    //如果只有一个为空，那么肯定不对称，返回false
            return false;
        if(l->val!=r->val)      //如果值不等，也是不对成，返回false
            return false;
        else{
            /*
             *下面可以说是递归的主体，注意左右两边的节点是对称判断的，例如左边的右节点对应右边的左节点
             */
            return symmetric(l->left, r->right) && symmetric(r->left, l->right);
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
        {
            t = NULL;
        }
        else
        {
            t = new TreeNode(s[pos] - '0');
            t->left = CreateBiTree(s, pos);
            t->right = CreateBiTree(s, pos);
        }
    }
    return t;
}

TreeNode *createBiTree(string &s)
{
    int pos = -1;
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
    string s = "123##4##24##4##";
    auto t = createBiTree(s);
    midPrint(t);

    Solution solution;
    cout << endl<<solution.isSymmetric(t)<<endl;
    system("pause");
    return 0;
}