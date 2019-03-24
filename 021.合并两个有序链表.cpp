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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head=new ListNode(0);
        ListNode *node;
        ListNode *newHead = head;
        while(l1&&l2){
            if(l1->val>l2->val){
                node = new ListNode(l2->val);
                head->next = node;
                head = node;
                l2 = l2->next;
            }
            else if(l1->val<l2->val){
                node = new ListNode(l1->val);
                head->next = node;
                head = node;
                l1 = l1->next;
            }
            else{
                node = new ListNode(l1->val);
                head->next = node;
                head = node;
                node = new ListNode(l1->val);
                head->next = node;
                head = node;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        while(l1&&!l2){
            node = new ListNode(l1->val);
            head->next = node;
            head = node;
            l1 = l1->next;
        }
        while(!l1&&l2){
            node = new ListNode(l2->val);
            head->next = node;
            head = node;
            l2 = l2->next;
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
    ListNode *head1=new ListNode(1);
    ListNode *head2 = new ListNode(1);
    ListNode *node;
    int a[] = {2, 4,5,6,7};
    int b[] = {3, 4};
    ListNode *head = head1;
    for (int i = 0; i < 5;++i){
        node = new ListNode(a[i]);
        head->next = node;
        head = node;
    }
    head = head2;
    for (int i = 0; i < 2; ++i){
        node = new ListNode(b[i]);
        head->next = node;
        head = node;
    }
    print(head1);
    print(head2);
    cout << "ans:\n";
    print(solution.mergeTwoLists(head1, head2));

    system("pause");
    return 0;
}