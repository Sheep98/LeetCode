#include "bits/stdc++.h"

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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;

        ListNode *min = new ListNode(0);
        ListNode *max = new ListNode(0);
        ListNode *p = head;
        ListNode *pMax = max, *pMin = min;
        while (p != NULL)
        {
            if (p->val < x)
            {
                pMin->next = p;
                pMin = p;
                p = p->next;
                pMin->next = NULL;
            }
            else
            {
                pMax->next = p;
                pMax = p;
                p = p->next;
                pMax->next = NULL;
            }
        }
        pMin->next = max->next;
        return min->next;
    }
};

ListNode *createList(const vector<int> &v)
{
    ListNode *head = new ListNode(v[0]);
    ListNode *p = head;
    ListNode *node;
    for (int i = 1; i < v.size(); ++i)
    {
        node = new ListNode(v[i]);
        p->next = node;
        p = node;
    }
    return head;
}

void printList(ListNode *head)
{
    if (!head)
        return;
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> list = {1, 4, 3, 2, 5, 2};
    auto a = createList(list);
    printList(a);
    Solution s;
    auto a2 = s.partition(a, 3);
    printList(a2);

    system("pause");
    return 0;
}