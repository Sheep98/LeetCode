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
    ListNode *middleNode(ListNode *head){
        if(head->next==nullptr)
            return head;
        if(head->next->next==nullptr)
            return head->next;
        int length=0;
        ListNode *first = head;
        while(first){
            first = first->next;
            ++length;
        }
        ListNode *secend = head;
        for (int i = 0; i < length / 2; ++i)
        {
            secend = secend->next;
        }
        return secend;
    
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
    int a[] = {1,2};
    ListNode *node;
    ListNode *head = head1;
    for (int i = 0; i < 2; i++)
    {
        node = new ListNode(a[i]);
        head->next = node;
        head = node;
    }
    print(head1);
    solution.middleNode(head1);
    system("pause");
    return 0;
}