#include"bits/stdc++.h"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* createListNode(const vector<int> &a){
    if(a.empty())
        return NULL;
    ListNode *head=new ListNode(a[0]);
    ListNode *head1 = head;
    ListNode *node;
    for (int i = 1; i < a.size();++i){
        node = new ListNode(a[i]);
        head1->next = node;
        head1 = node;
    }
    return head;
}

void printList(ListNode *head){
    while(head!=NULL){
        cout << head->val<<" ";
        head = head->next;
    }
    cout << endl;
}


class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head||!head->next)
            return head;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *pre = start;
        while (pre->next) {
            ListNode *cur = pre->next;
            while (cur->next && cur->next->val == cur->val) cur = cur->next;
            if (cur != pre->next) pre->next = cur->next;
            else pre = pre->next;
        }
        return start->next;

    }
};

int main(){
    vector<int> list = {1, 1, 1, 2,2,2,3,3,4,5,5,5,6,6,6,7,8,8,9};
    auto head= createListNode(list);
    printList(head);
    Solution s;
    printList(s.deleteDuplicates(head));
    system("pause");
    return 0;
}