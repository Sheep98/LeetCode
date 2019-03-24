#include <iostream>

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
    ListNode *reverseList(ListNode *head){
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
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
    ListNode *head1 = new ListNode(0);
    int a[] = {1, 2, 3, 4, 5};
    ListNode *node;
    ListNode *head = head1;
    for (int i = 0; i < 5;i++){
        node=new ListNode(a[i]);
        head->next=node;
        head = node;
    }
    print(head1);
    print(solution.reverseList(head1));
    system("pause");
    return 0;
}