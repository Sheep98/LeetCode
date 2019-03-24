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
    bool hasCycle(ListNode *head){
        if(!head||!head->next)
            return false;
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                return true;
        }
        return false;
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
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(1);
    int a[] = {2, 3, 4};
    ListNode *node;
    ListNode *head = head1;
    for(auto n:a){
        node = new ListNode(n);
        head->next = node;
        head = node;
    }
    head->next = head1;
    head = head2;
    for (auto n : a)
    {
        node = new ListNode(n);
        head->next = node;
        head = node;
    }
    Solution s;
   // print(head1);
    cout <<"head1: " <<s.hasCycle(head1)<<endl;
    cout << "head2: " << s.hasCycle(head2) << endl;
    system("pause");
    return 0;
}