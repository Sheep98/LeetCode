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
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

ListNode *re(ListNode *head, int i)
{
    while (head != NULL)
    {
        if (head->val == i)
            return head;
        head = head->next;
    }
    return head;
}

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
    ListNode *head2 = new ListNode(0);
    ListNode *head = NULL;
    int a[] = {4, 5, 1, 9};
    head = head1;
    ListNode *node;
    for (int i = 0; i < 4; i++)
    {
        node = new ListNode(a[i]);
        head->next = node;
        head = node;
    }
    print(head1);
    solution.deleteNode(re(head1, 5));
    print(head1);
    system("pause");
    return 0;
}