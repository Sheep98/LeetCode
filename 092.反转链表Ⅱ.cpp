#include <iostream>
#include<stack>
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {    
        if(head==NULL&&n==m)
            return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *left =newHead;
        
        for (int i = 0; i < m -1;++i){
            left=left->next;
        }
        ListNode *temp = left->next;
        
        for (int i = 0; i < n - m;++i){
            ListNode *p = temp->next;
            temp->next = p->next;
            p->next = left->next;
            left->next = p;
        }
        return newHead->next;
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
    ListNode *head=new ListNode(0);
    ListNode *node;
    ListNode *head1;
    head1 = head;
    for (int i = 1; i < 2; ++i){
        node = new ListNode(i);
        head->next = node;
        head = node;
    }
    print(head1);
    print(solution.reverseBetween(head1, 1, 2));
    system("pause");
    return 0;
}