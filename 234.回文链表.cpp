#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    bool isPalindrome(ListNode *head){
        if(head->next==NULL||head==NULL)
            return true;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        auto left = v.cbegin();
        auto right = v.cend()-1;
        while(left<right){
            if(*left!=*right)
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;
    ListNode *head1;
    //= new ListNode(0);
    ListNode *head2 = new ListNode(0);
    ListNode *head = NULL;
    int a[] = {1,1,0,2};
    head = head1;
    ListNode *node;
    // for (int i = 0; i < 4; i++)
    // {
    //     node = new ListNode(a[i]);
    //     head->next = node;
    //     head = node;
    // }
    //print(head1);
    cout << solution.isPalindrome(head1)<<endl;
    system("pause");
    return 0;
}