#include<iostream>
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *p = head;
        if (!head || !head->next)
            return head;
        ListNode *fast = head->next;
        ListNode *low = head;
        low->next = swapPairs(fast->next);
        fast->next = low;
        return fast;
    }
};