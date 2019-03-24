#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> v;
        if (!root)
        {
            return v;
        }
        v.push_back(root->val);
        vector<int> tmp = preorderTraversal(root->left);
        if (!tmp.empty())
        {
            for (int i = 0; i < tmp.size(); i++)
            {
                v.push_back(tmp[i]);
            }
        }
        vector<int> tmp2 = preorderTraversal(root->right);
        if (!tmp2.empty())
        {
            for (int i = 0; i < tmp2.size(); i++)
            {
                v.push_back(tmp2[i]);
            }
        }
        return v;
    }
};

class MySolution{
    public:
    vector<int> MyPreorderTraversal(TreeNode *root){
        vector<int> v;
        return v;//未完成，需要补充。。。
    }
};

int main(){
    TreeNode *tree1 = new TreeNode(0);
    TreeNode *tree=tree1;
    int a[] = {2, 3, 4, 5, 6, 7};
    TreeNode *lnode;
    TreeNode *rnode;
    lnode = new TreeNode(a[0]);
    rnode = new TreeNode(a[1]);
    tree->left = lnode;
    tree->right = rnode;
    lnode->left = new TreeNode(a[2]);
    lnode->right = new TreeNode(a[3]);
    Solution s;
    auto v = s.preorderTraversal(tree1);
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
