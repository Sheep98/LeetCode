#include"bits/stdc++.h"
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        queue<TreeLinkNode *> que;
        que.push(root);
        TreeLinkNode *node;
        queue<TreeLinkNode *> newque;
        while(!que.empty()){
            node = que.front();
            que.pop();
            if(node->left!=NULL)
                newque.push(node->left);
            if(node->right!=NULL)
                newque.push(node->right);
            if(que.empty()){
                node->next = NULL;
                que = newque;
                while(!newque.empty())
                    newque.pop();
                continue;
            }
            node->next = que.front();
        }
    }
};

TreeLinkNode *CreateBiTree(string &s, int &pos)
{
    ++pos;
    TreeLinkNode *t;
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
            t = new TreeLinkNode(s[pos] - '0');
            t->left = CreateBiTree(s, pos);
            t->right = CreateBiTree(s, pos);
        }
    }
    return t;
}

TreeLinkNode *createBiTree(string &s)
{
    int pos = -1;
    return CreateBiTree(s, pos);
}

void midPrint(TreeLinkNode *t)
{
    if (t == NULL)
        return;
    cout << t->val << " ";
    midPrint(t->left);
    midPrint(t->right);
}

void leftSave(TreeLinkNode* root,vector<TreeLinkNode*> &left){
    if(!root)
        return;
    left.push_back(root);
    leftSave(root->left,left);
    return;
}

void printNext(TreeLinkNode* root)
{
    if(!root)
        return;
    while(root!=NULL){
        cout << root->val << "->";
        root = root->next;
    }
    cout << endl;
}

int main(){
    string s = "12345##";
    auto t=createBiTree(s);
    midPrint(t);
    Solution a;
    a.connect(t);
    vector<TreeLinkNode *> left;
    leftSave(t, left);
    cout << endl;
    for (auto n:left)
    {
        printNext(n);
    }

    system("pause");
    return 0;
}