#include <iostream>
#include <stack>
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL||k==0)
            return head;
        ListNode *p = head;
        int length = 0;
        while(p->next!=NULL){
            p = p->next;
            length++;
        }
        k = length - k%(length+1);
        p->next = head;
        while(k>0){
            k--;
            head = head->next;
        }
        ListNode *newHead = head->next;
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
    ListNode *head = new ListNode(1);
    ListNode *node;
    ListNode *head1;
    head1 = head;
    int a[] = {2,3};
    for (auto n:a)
    {
        node = new ListNode(n);
        head->next = node;
        head = node;
    }
    print(head1);
    auto n=solution.rotateRight(head1,4);
    print(n);
    system("pause");
    return 0;
}