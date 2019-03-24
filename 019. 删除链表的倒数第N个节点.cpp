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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *first=head;
        ListNode *second=head;
        for (int i = 0; i <n;i++){
            second = second->next;
        }
        if(second==NULL)
            return first->next;
        while(second->next!=NULL){
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
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
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *head = l1;
    ListNode *node;
    //for (int i = 2; i < 6;i++){
      //  node = new ListNode(i);
        //l1->next = node;
        //l1 = node;
    //}
    print(head);
    print(s.removeNthFromEnd(head,1));
    
    system("pause");
    return 0;
}